/* File: Subsets.cpp
 *
 * A program to list off all subsets of a master set.
 */
#include <iostream>
#include <string>
#include "set.h"
#include "console.h"
using namespace std;

/* Recursive function to list subsets. There are two parameters
 * here. The first is the set of elements for which we haven't
 * yet made a decision. The second is the set of elements we
 * have committed to include in our set along this branch of the
 * decision tree.
 */
void listSubsetsRec(const Set<int>& elems,
                    const Set<int>& soFar) {
    /* Base Case: All decisions made. */
    if (elems.isEmpty()) {
        cout << soFar << endl;
    }
    /* Otherwise: Try all decisions. */
    else {
        int elem = elems.first();
        Set<int> remaining = elems - elem;

        /* Option 1: Include this element. */
        listSubsetsRec(remaining, soFar + elem);

        /* Option 2: Exclude this element. */
        listSubsetsRec(remaining, soFar);
    }
}

/* This wrapper function makes it more convenient for people to
 * call our recursive function. They just tell us what set to
 * list subsets of and we take care of the rest!
 */
void listSubsetsOf(const Set<int>& elems) {
    listSubsetsRec(elems, {});
}

int main() {
    listSubsetsOf({1, 2, 3, 4, 5});
    return 0;
}

