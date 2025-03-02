#include <iostream>
#include <iomanip>
#include "inputchi/hud.h"

using namespace std;

void happy_inputchi()
{
    cout << "║           ████████████                 ║" << endl;
    cout << "║        ████          █████             ║" << endl;
    cout << "║       ██                 ███           ║" << endl;
    cout << "║     ███                    ██          ║" << endl;
    cout << "║     █                        █         ║" << endl;
    cout << "║     █                         ██       ║" << endl;
    cout << "║   ██    ███       ███          ██      ║" << endl;
    cout << "║   █     ███       ███            ██    ║" << endl;
    cout << "║  ██     ███       ███             ██   ║" << endl;
    cout << "║ ██       ██        ██              ██  ║" << endl;
    cout << "║██                           █        █ ║" << endl;
    cout << "║█                            █        ██║" << endl;
    cout << "║█                            █         █║" << endl;
    cout << "║█                         ███          █║" << endl;
    cout << "║██                  ███████           ██║" << endl;
    cout << "║ ███                                 ██ ║" << endl;
    cout << "║   ███                             ██   ║" << endl;
    cout << "║     ██████                   ██████    ║" << endl;
    cout << "║          ████████████████████          ║" << endl;
}

void sad_inputchi()
{
    cout << "║           ████████████                 ║" << endl;
    cout << "║        ████          █████             ║" << endl;
    cout << "║       ██                 ███           ║" << endl;
    cout << "║     ███                    ██          ║" << endl;
    cout << "║     █                        █         ║" << endl;
    cout << "║     █                         ██       ║" << endl;
    cout << "║   ██    ███       ███          ██      ║" << endl;
    cout << "║   █     ███       ███            ██    ║" << endl;
    cout << "║  ██     ███       ███             ██   ║" << endl;
    cout << "║ ██       ██        ██              ██  ║" << endl;
    cout << "║██                                    █ ║" << endl;
    cout << "║█                                     ██║" << endl;
    cout << "║█                      ████████        █║" << endl;
    cout << "║█                   ███                █║" << endl;
    cout << "║██                ███                 ██║" << endl;
    cout << "║███              █                  ██ ║" << endl;
    cout << "║   ███                             ██   ║" << endl;
    cout << "║     ██████                   ██████    ║" << endl;
    cout << "║          ████████████████████          ║" << endl;
}

void print_hud(int food, int time_left, bool hangry)
{
    system("clear");
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║              Inputchi HUD              ║" << endl;
    cout << "╠════════════════════════════════════════╣" << endl;
    cout << "║ Comida: " << setw(3) << food << "                            ║" << endl;
    cout << "║ Tempo:  " << setw(3) << time_left << "                            ║" << endl;
    cout << "╠════════════════════════════════════════╣" << endl;

    if (hangry)
    {
        sad_inputchi();
        cout << "║            I'm hungry!                 ║" << endl;
        cout << "╚════════════════════════════════════════╝" << endl;
    }
    else
    {
        happy_inputchi();
        cout << "║            I'm happy!                  ║" << endl;
        cout << "╚════════════════════════════════════════╝" << endl;
    }
}