/* File: EatYourWords.cpp
 *
 * A program to find all English tautonyms.
 */
#include <iostream>
#include <string>
#include "console.h"
#include "lexicon.h"
#include "simpio.h"
#include "strlib.h"
#include "map.h"
#include "set.h"
using namespace std;

/* Given a string, returns whether it's a tautonym, a string
 * formed by gluing the same string together twice.
 */
bool isTautonym(const string& word) {
    /* Odd-length strings can't be tautonyms. */
    if (word.length() % 2 != 0) {
        return false;
    }

    /* Compare the first and second halves of the string. */
    int half = word.length() / 2;
    return word.substr(0, half) == word.substr(half);
}

int main() {
    Lexicon english("EnglishWords.txt");

    /* Build a map from letters to all the words that start with that letter. */
    Map<char, Lexicon> wordsByFirstLetter;
    for (string word: english) {
        wordsByFirstLetter[word[0]].add(word);
    }

    /* Have some fun! */
    while (true) {
        char ch = toLowerCase(getChar("Enter first letter: "));

        /* Validate that the input starts some tautonym. */
        if (wordsByFirstLetter.containsKey(ch)) {
            /* Combining the tautonyms example from class and the words by letter
             * example, print all tautonyms starting with that letter.
             */
            for (string word: wordsByFirstLetter[ch]) {
                if (isTautonym(word)) {
                    cout << word << endl;
                }
            }
        }
    }
}
