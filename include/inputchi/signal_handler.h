#ifndef SIGNAL_HANDLER_H
#define SIGNAL_HANDLER_H

#include <csignal>
#include <iostream>

using namespace std;

extern volatile sig_atomic_t stop;

void handle_signal(int signal);

#endif // SIGNAL_HANDLER_H
