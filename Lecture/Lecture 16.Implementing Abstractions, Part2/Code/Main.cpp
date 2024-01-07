/*****************************************************
 * File: Main.cpp
 *
 * A program to run simple tests on our custom Stack.
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include "OurStack.h"
#include "simpio.h"
#include "random.h"
#include "console.h"
using namespace std;

const int kNumElems = 7;

void runSimpleTests() {
    OurStack stack;

    /* Load the stack with random values. */
    cout << "Pushing elements onto the stack:" << endl;
    for (int i = 0; i < kNumElems; i++) {
        int value = randomInteger(0, 1000);
        cout << setw(6) << value;
        stack.push(value);
    }
    cout << endl;

    /* See what those values are. */
    cout << "Popping elements from the stack:" << endl;
    while (!stack.isEmpty()) {
        cout << setw(6) << stack.pop();
    }
    cout << endl;
}

void runTimeTests(int minSize, int maxSize, int stepSize) {
    cout << "Starting with an empty stack, how long does it take to execute a sequence of n pushes?" << endl;
    int numDigits = ceil(log(maxSize + 1) / log(10));
    for (int i = minSize; i <= maxSize; i += stepSize) {
        double startTime = clock();

        OurStack stack;
        for (int elem = 0; elem < i; elem++) {
            stack.push(elem);
        }

        double elapsed = (clock() - startTime) / double(CLOCKS_PER_SEC);
        cout << "Pushing n = " << setw(numDigits) << i << " items: " << elapsed << "s" << endl;
    }

}

int main() {
    cout << "Welcome to the Stack Test Driver!" << endl;
    cout << "Please choose an option: " << endl;
    cout << "  1: Simple tests" << endl;
    cout << "  2: Easy time tests" << endl;
    cout << "  3: Hard time tests" << endl;
    cout << "  4: Very hard time tests" << endl;
    cout << "  5: Call it a day" << endl;

    while (true) {
        int option = getInteger("Your choice: ");
        if (option == 1) runSimpleTests();
        else if (option == 2) runTimeTests(5000, 50000, 5000);
        else if (option == 3) runTimeTests(1000000, 10000000, 1000000);
        else if (option == 4) runTimeTests(10000000, 100000000, 10000000);
        else if (option == 5) break;
        else cerr << "Sorry, I don't understand." << endl;
    }

    cout << "Have a nice day!" << endl;
    return 0;
}
