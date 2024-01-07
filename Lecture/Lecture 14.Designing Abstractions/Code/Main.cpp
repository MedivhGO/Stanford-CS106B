#include <iostream>
#include "console.h"
#include "RandomBag.h"
using namespace std;

/* Prints out how many items are in the bag. Note that we have to mark the
 * RandomBag::size() member function const for this to work, since otherwise
 * C++ won't know that member function doesn't mutate the bag.
 */
void printBagSize(const RandomBag& bag) {
    cout << "The bag has " << bag.size () << " things in it." << endl;
}

int main() {
    /* Some sample code using the RandomBag. */
    RandomBag bag;

    for (int i = 0; i < 10; i++) {
        bag.add(i);
    }

    printBagSize(bag);

    while (!bag.isEmpty()) {
        cout << bag.removeRandom() << endl;
    }

    return 0;
}
