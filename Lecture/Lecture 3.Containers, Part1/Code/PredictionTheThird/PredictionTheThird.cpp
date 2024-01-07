/* File: PredictionTheThird.cpp
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
void dream(Vector<int> numbers) {
    numbers[1] = 1963;
}

int main() {
    Vector<int> values = { 1929, 1955, 1964 };
    dream(values);
    cout << values << endl; // <-- Here
    return 0;
}















