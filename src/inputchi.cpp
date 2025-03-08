// src/inputchi.cpp
#include "inputchi/hud.h"
#include "inputchi/signal_handler.h"
#include "inputchi/inputchi.h"
#include "inputchi/gui.h"

using namespace std;

int inputchi(DisplayMode mode)
{
    signal(SIGINT, handle_signal);

    int fd = open("/dev/input/event3", O_RDONLY);
    if (fd == -1)
    {
        cout << "Error: Could not open file" << endl;
        return 1;
    }

    struct input_event ev;

    int count = 0;
    int food = 0;
    int start_time = time(0);
    int hangry = 0;

    // Inicializar a GUI se necessário
    InputchiGUI gui;
    if (mode == DisplayMode::GUI)
    {
        if (!gui.initialize())
        {
            cout << "Error: Could not initialize GUI" << endl;
            close(fd);
            return 1;
        }
    }

    while (!stop && (mode == DisplayMode::CLI || gui.isOpen()))
    {
        // Processar eventos da GUI se estiver no modo GUI
        if (mode == DisplayMode::GUI)
        {
            gui.processEvents();
        }

        fd_set set;
        struct timeval timeout;

        FD_ZERO(&set);
        FD_SET(fd, &set);

        timeout.tv_sec = 0;
        timeout.tv_usec = 100000; // 100ms

        int rv = select(fd + 1, &set, NULL, NULL, &timeout);

        if (rv == -1)
        {
            cout << "Error: select() failed" << endl;
            close(fd);
            return 1;
        }
        else if (rv == 0)
        {
            // Timeout occurred, update the display
        }
        else
        {
            read(fd, &ev, sizeof(struct input_event));

            if (ev.type == EV_KEY && (ev.value == 1 || ev.value == 2))
            {
                count++;

                if (count % KEYS_TO_FOOD_CONVERSION_FACTOR == 0)
                {
                    food++;
                }
            }
        }

        if (time(0) - start_time > TIME_TO_EAT)
        {
            if (food <= 0)
            {
                hangry = 1;
            }
            else
            {
                food--;
                hangry = 0;
            }
            start_time = time(0);
        }

        int time_left = TIME_TO_EAT - (time(0) - start_time);

        // Atualizar a interface adequada
        if (mode == DisplayMode::CLI)
        {
            print_hud(food, time_left, hangry);
        }
        else
        {
            gui.update(food, time_left, hangry);
            gui.render();
        }
    }

    close(fd);
    return 0;
}