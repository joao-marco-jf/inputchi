#ifndef INPUTCHI_H
#define INPUTCHI_H

#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <ctime>

#define TIME_TO_EAT 60
#define KEYS_TO_FOOD_CONVERSION_FACTOR 250

int inputchi();

#endif // INPUTCHI_H
