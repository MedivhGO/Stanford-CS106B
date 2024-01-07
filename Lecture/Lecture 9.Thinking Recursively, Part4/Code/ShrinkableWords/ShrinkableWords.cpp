/* File: ShrinkableWords.cpp
 *
 * Code to find all the shrinkable words in English!
 */
#include <iostream>
#include <string>
#include "lexicon.h"
#include "console.h"
using namespace std;

/* A word is shrinkable if it can be reduced to a single letter
 * by deleting individual letters one at a time, leaving a word
 * at each step, until a single letter remains.
 */
bool isShrinkableWord(const string& word,
                      const Lexicon& english) {
    /* Base Case: If you aren't a word, period, then
     * you aren't a shrinkable word.
     */
    if (!english.contains(word)) {
        return false;
    }

    /* Base Case: If you are a single-letter word, then
     * you are a shrinkable word.
     */
    if (word.length() == 1) {
        return true;
    }

    /* Recursive Case: Try removing each letter, one at
     * a time, to see if any of the words formed that
     * way are shrinkable.
     */
    for (int i = 0; i < word.length(); i++) {
        string shrunken = word.substr(0, i) +
                          word.substr(i + 1);

        /* If this is a shrinkable word, then our original
         * word is shrinkable too!
         */
        if (isShrinkableWord(shrunken, english)) {
            return true;
        }
    }

    /* Oh fiddlesticks. */
    return false;
}

int main() {
    Lexicon english("EnglishWords.txt");

    for (string word: english) {
        if (word.length() >= 9 &&
            isShrinkableWord(word, english)) {
            cout << word << endl;
        }
    }

    return 0;
}
