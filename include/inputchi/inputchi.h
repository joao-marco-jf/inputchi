// include/inputchi/inputchi.h
#ifndef INPUTCHI_H
#define INPUTCHI_H

#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <ctime>

#define TIME_TO_EAT 60
#define KEYS_TO_FOOD_CONVERSION_FACTOR 100

// Adicione uma flag para escolher entre CLI e GUI
enum class DisplayMode
{
    CLI,
    GUI
};

int inputchi(DisplayMode mode = DisplayMode::CLI);

#endif // INPUTCHI_H