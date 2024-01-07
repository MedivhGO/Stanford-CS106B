/* File: FunWithStrings.cpp
 *
 * A program for playing around with C++ strings!
 */
#include <iostream>
#include <string>
#include "simpio.h"
#include "console.h"
using namespace std;

string reverseOf(string input);

int main() {
    while (true) {
        string text = getLine("Enter some text: ");
        cout << "Behold, it is now \"" << reverseOf(text) << "\"." << endl << endl;
    }
}

/* Given a string, returns the reverse of that string. */
string reverseOf(string input) {
    /* Base Case: If the string is empty, then it's its own reverse. */
    if (input == "") {
        return "";
    }
    /* Recursive Case: Reverse everything but the first character, then tack
     * the first character onto the back.
     */
    else {
        return reverseOf(input.substr(1)) + input[0];
    }
}













