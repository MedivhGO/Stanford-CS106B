/*****************************************************
 * File: Main.cpp
 *
 * A program to play around with hash functions!
 */
#include <iostream>
#include "HashFunction.h"
#include "vector.h"
#include "console.h"
#include "simpio.h"
using namespace std;

int main() {
    Vector<string> santaClaraCountyCities = {
        "Campbell",
        "Cupertino",       // Home of Apple, Inc.
        "Gilroy",          // Of the famous garlic festival
        "Los Altos",       // Not to be confused with Los Altos Hills
        "Los Altos Hills", // Not to be confused with Los Altos
        "Los Gatos",
        "Milpitas",
        "Monte Sereno",
        "Morgan Hill",
        "Mountain View",   // Home of Alphabet, Inc.
        "Palo Alto",
        "San José",        // 10th largest city in the US!
        "Santa Clara",     // Home of Levi's Stadium
        "Saratoga",
        "Sunnyvale"        // Former fruitpacking capital
    };

    // Lexicon english("EnglishWords.txt");
    //
    //  HashFunction<string>: Inputs are strings.
    //  Outputs: integers. Question: Which RANGE of integers?
    //
    HashFunction<string> hashFn(santaClaraCountyCities.size());

    cout << hashFn("Keith") << endl;
    cout << hashFn("Sherry") << endl;

    while (true) {
        string name = getLine("Enter your name: ");
        int hashCode = hashFn(name);
        cout << "You need to canvas in " << santaClaraCountyCities[hashCode] << endl;
    }

    return 0;
}
