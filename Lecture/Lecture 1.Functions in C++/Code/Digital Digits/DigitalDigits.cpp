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

int main() {
    int n = getInteger("Enter an integer: ");
    int digitSum = sumOfDigitsOf(n);
    cout << n << " sums to " << digitSum << endl;

    return 0;
}

/* Returns the sum of the digits of the number n. */
int sumOfDigitsOf(int n) {
    int result = 0;

    /* Given an integer n, the value n % 10 represents the last
     * digit of the number (the REMAINDER when we divide n by 10).
     * The value n / 10 represents all the digits except the last
     * (the QUOTIENT when we divide n by 10.)
     */
    while (n > 0) {
        result += (n % 10);
        n /= 10;
    }

    return result;
}











