#include "SoundPlayer.h"
#include "gthread.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int kFilenameWidth = 20;

void playSound(const string& filename, double ms) {
    cout << setw(kFilenameWidth) << filename << " (" << ms << "ms)" << endl;
    GThread::getCurrentThread()->sleep(ms);
}
