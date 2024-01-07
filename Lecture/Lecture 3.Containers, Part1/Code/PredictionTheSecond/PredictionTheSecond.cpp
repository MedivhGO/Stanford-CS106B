/* File: PredictionTheSecond.cpp
 *
 * What will this program print?
 */
#include <iostream>
#include <string>
#include "vector.h"
#include "console.h"
using namespace std;

/* By itself, this has no effect. Change the parameter to a reference
 * parameter to make the magic happen.
 */
void gollyGee(string text) {
    text[0] = 'g';
}

int main() {
    string message = "wiggle";
    gollyGee(message);
    cout << message << endl; // <-- Here
    return 0;
}





