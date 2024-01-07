/* File: MaxOf.cpp
 *
 * A program showing off several ways to find the maximum element of a Vector.
 */
#include <iostream>
#include <algorithm>
#include "vector.h"
#include "console.h"
using namespace std;

int maxOf(const Vector<int>& elems);

int main() {
    Vector<int> v = { 137, 106, 107, 166, 103, 261, 109 };
    cout << maxOf(v) << endl;
    return 0;
}

/* Finds the maximum element in a vector that's presumed to have at least one
 * element in it.
 */
int maxOf(const Vector<int>& elems) {
    /* Base case: if there's just one element, it's by default the biggest. */
    if (elems.size() == 1) {
        return elems[0];
    }
    /* Othewise, the maximum element is either (1) the first element or (2)
     * the largest element in the remaining elements.
     */
    else {
        int first = elems[0];
        Vector<int> rest = elems.subList(1);
        return max(first, maxOf(rest));
    }
}













