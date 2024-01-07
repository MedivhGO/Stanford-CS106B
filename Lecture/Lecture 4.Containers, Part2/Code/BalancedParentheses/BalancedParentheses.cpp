/* File: BalancedParentheses.cpp
 *
 * A program that checks whether the parentheses in a string are
 * balanced.
 */
#include <iostream>
#include <string>
#include "stack.h"
#include "simpio.h"
#include "console.h"
using namespace std;

/* Helper functions that test various properties of
 * characters.
 */
bool isOpenParenthesis(char ch);
bool isCloseParenthesis(char ch);
bool parensMatch(char open, char close);

/* Given a string, are the parentheses balanced within
 * that string? The parameter is accepted by const
 * reference because (1) we don't want to copy the
 * text (that's wasteful), and (2) we don't want this
 * function to make changes to it.
 */
bool parensAreBalancedIn(const string& text) {
    Stack<char> unmatchedOpens;

    for (char ch: text) {
        if (isOpenParenthesis(ch)) {
            unmatchedOpens.push(ch);
        } else if (isCloseParenthesis(ch)) {
            /* There must be something to match against. */
            if (unmatchedOpens.isEmpty()) {
                return false;
            }

            /* It has to match this close parenthesis. */
            char open = unmatchedOpens.pop();
            if (!parensMatch(open, ch)) {
                return false;
            }
        }
    }

    /* When we're done, we should have matched everything. */
    return unmatchedOpens.isEmpty();
}

int main() {
    while (true) {
        string text = getLine("Enter some text: ");
        if (parensAreBalancedIn(text)) {
            cout << "Yep!" << endl;
        } else {
            cout << "Nah" << endl;
        }
    }
}

bool isOpenParenthesis(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}
bool isCloseParenthesis(char ch) {
    return ch == ')' || ch == ']' || ch == '}';
}
bool parensMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}
