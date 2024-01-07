#include <iostream>
#include <string>
#include "vector.h"
#include "lexicon.h"
#include "console.h"
#include "simpio.h"
using namespace std;

bool isShrinkable(const string& word,
                  const Lexicon& english,
                  Vector<string>& shrinkingSequence) {
    /* Base Case: Non-words aren't shrinkable words. */
    if (!english.contains(word)) {
        return false;
    }

    /* Base Case: Any word of length 1 is shrinkable. */
    if (word.length() == 1) {
        shrinkingSequence = { word };
        return true;
    }

    /* Recursive step: look at all words you can
     * form by removing a single letter. If any of
     * them are shrinkable, the whole word is
     * shrinkable!
     */
    for (int i = 0; i < word.length(); i++) {
        string shrunken = word.substr(0, i) +
                          word.substr(i+1);
        if (isShrinkable(shrunken, english,
                         shrinkingSequence)) {
            shrinkingSequence += word;
            return true;
        }
    }

    /* If none of those options worked, this string
     * cannot be shrunk.
     */
    return false;
}

int main() {
    Lexicon english("EnglishWords.txt");
    while (true) {
        string word = getLine("Enter a word: ");

        Vector<string> sequence;
        if (isShrinkable(word, english, sequence)) {
            cout << "It's shrinkable!" << endl;
            for (string step: sequence) {
                cout << step << endl;
            }
        } else {
            cout << "Nothing to see here, folks; move along." << endl;
        }
    }
}
