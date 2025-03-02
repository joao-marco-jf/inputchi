
#include "inputchi/hud.h"
#include "inputchi/signal_handler.h"
#include "inputchi/inputchi.h"

using namespace std;

int inputchi()
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

    while (!stop)
    {
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
            // Timeout occurred, update the HUD
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

        print_hud(food, TIME_TO_EAT - (time(0) - start_time), hangry);
    }

    close(fd);
    return 0;
}
