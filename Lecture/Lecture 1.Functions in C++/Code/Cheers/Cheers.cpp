#include <iostream>
#include "console.h"
using namespace std;

/* This is a forward declaration (function prototype) saying to C++
 * "I will eventually write a function named cheer that takes in an
 * integer and doesn't return anything." Think of it as an IOU for
 * a function.
 */
void cheer(int numTimes);

/* This is where things begin! */
int main() {
    cheer(137);
    return 0;
}

/* Here's the actual implementation of cheer, which is where the magic
 * happens.
 */
void cheer(int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        cout << "Hip hip, hooray!" << endl;
    }
}
