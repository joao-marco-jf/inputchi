#include "inputchi/signal_handler.h"

volatile sig_atomic_t stop = 0;

void handle_signal(int signal)
{
    cout << "Caught signal " << signal << endl;
    stop = 1;
}
