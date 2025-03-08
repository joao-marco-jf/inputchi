// src/main.cpp
#include "inputchi/inputchi.h"
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    DisplayMode mode = DisplayMode::CLI;

    // Verificar argumentos de linha de comando para definir o modo
    if (argc > 1)
    {
        string arg = argv[1];
        if (arg == "--gui" || arg == "-g")
        {
            mode = DisplayMode::GUI;
        }
    }

    inputchi(mode);
    return 0;
}