/*****************************************************
 * File: Main.cpp
 *
 * A program to play around with our new hash set!
 */
#include <iostream>
#include "OurSet.h"
#include "console.h"
#include "simpio.h"
using namespace std;

int main() {
    OurSet set;

    /* The nine muses. */
    set.add("Calliope");    // Muse of epic poetry
    set.add("Polyhymnia");  // Muse of sacred poetry
    set.add("Euterpe");     // Muse of flutes and lyric poetry
    set.add("Terpsichore"); // Muse of dance
    set.add("Urania");      // Muse of astronomy
    set.add("Clio");        // Muse of history
    set.add("Erato");       // Muse of love poetry
    set.add("Melpomene");   // Muse of tragedy
    set.add("Thalia");      // Muse of comedy and pastoral poetry
                            // Thanks, Wikipedia!
    while (true) {
        string name = getLine("What are you musing about? ");
        if (set.contains(name)) {
            cout << "Muse-ic to my ears!" << endl;
        } else {
            cout << "We are not a-mused." << endl;
        }
    }

    return 0;
}
