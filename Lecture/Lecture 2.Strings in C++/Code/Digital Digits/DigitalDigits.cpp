/* File: DigitalDigits.cpp
 *
 * A program that explores properties of digits of
 * numbers!
 */
#include <iostream>
#include "simpio.h"
#include "console.h"
using namespace std;

int sumOfDigitsOf(int n);
int digitalRootOf(int n);

int main() {
    while (true) {
        int val = getInteger("For this trick, I need a number! ");
        cout << "Its digital root is " << digitalRootOf(val) << "." << endl << endl;
    }
}

int digitalRootOf(int n) {
    /* Base case: Single-digit number. */
    if (n < 10) {
        return n;
    }
    /* Recursive case: Multiple digits. */
    else {
        return digitalRootOf(sumOfDigitsOf(n));
    }
}

/* Given a number n, returns the sum of the digits of n. */
int sumOfDigitsOf(int n) {
    /* Base case: The sum of all the digits of a number
     * with just one digit is that digit itself.
     */
    if (n < 10) {
        return n;
    }
    /* Recursive step: Peel off the last digit. */
    else {
        return sumOfDigitsOf(n / 10) + (n % 10);
    }
}

