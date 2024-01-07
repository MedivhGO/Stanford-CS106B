/* File: Permutations.cpp
 *
 * Functions to list off all permutations of a collection of elements.
 */
#include <iostream>
#include <string>
#include "set.h"
#include "console.h"
using namespace std;

Set<string> permutationsRec(const string& remaining,
                            const string& soFar) {
    /* Base Case: If we have no more decisions left,
     * we're left with what we committed to.
     */
    if (remaining == "") {
        return { soFar };
    }
    /* Recursive Case: You still decisions left.
     * Something comes next in the ordering. Try
     * all possibilities for what it could be.
     */
    else {
        Set<string> result;
        for (int i = 0; i < remaining.length(); i++) {
            string next = remaining.substr(0, i) +
                          remaining.substr(i + 1);

            result += permutationsRec(next,
                                      soFar + remaining[i]);
        }
        return result;
    }
}

/* Wrapper function:
 *
 * 1. Client (person calling permutations) wants to
 *    say "list permutations of this specific string."
 * 2. Implementation (the code for permutations) needs two
 *    parameters.
 *
 * So: we take in one parameter so the client is happy, and
 * we pass in two parameters so the implementation is happy.
 */
Set<string> permutationsOf(const string& str) {
    return permutationsRec(str, "");
}

int main() {
    Set<string> options = permutationsOf("CS106B");
    cout << "There are " << options.size()
         << " permutations." << endl;
    cout << options << endl;
    return 0;
}

