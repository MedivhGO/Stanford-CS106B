/* File: Crosswords.cpp
 *
 * A program to generate dense crosswords.
 */
#include <iostream>
#include <string>
#include "lexicon.h"
#include "grid.h"
#include "console.h"
using namespace std;

/**
 * Given a grid and a column, extracts the word at that column up to a certain
 * number of characters.
 *
 * @param grid The grid in question.
 * @param col Which column to extract
 * @param numRows How many rows to read
 * @return The contents of that column.
 */
string contentsOfColumn(const Grid<char>& grid, int col, int numRows) {
    string result;
    for (int row = 0; row < numRows; row++) {
        result += grid[row][col];
    }
    return result;
}

/**
 * Prints a crossword to the console.
 *
 * @param crossword The crossword in question.
 */
void printCrossword(const Grid<char>& crossword) {
    for (int row = 0; row < crossword.numRows(); row++) {
        for (int col = 0; col < crossword.numCols(); col++) {
            cout << crossword[row][col];
        }
        cout << endl;
    }
}

/**
 * Given a partially-filled crossword, check whether the columns
 * all start with strings that could, in principle, each be
 * extended into a full word.
 *
 * @param crossword The partial crossword.
 * @param nextRow   How many rows have been filled in.
 * @param colWords  Words that could appear in the columns.
 * @return Whether the columns could be extended to words.
 */
bool areColumnsFeasible(const Grid<char>& crossword,
                        int nextRow,
                        const Lexicon& colWords) {
    /* Check each column. */
    for (int col = 0; col < crossword.numCols(); col++) {
        /* Get its contents. */
        string column = contentsOfColumn(crossword, col, nextRow);
        if (!colWords.containsPrefix(column)) {
            return false;
        }
    }
    return true;
}


/* Can we fill in this partial crossword, starting at row nextRow? If so,
 * the function updates crossword with one possible solution.
 */
bool canMakeCrosswordRec(Grid<char>& crossword,
                         int nextRow,
                         const Lexicon& rowWords,
                         const Lexicon& colWords) {
    /* Base Case: Columns don't make sense. */
    if (!areColumnsFeasible(crossword,
                            nextRow,
                            colWords)) {
        return false;
    }

    /* Base Case: Everything filled! */
    if (nextRow == crossword.numRows()) {
        return true;
    }

    for (string word: rowWords) {
        /* Copy the word in. */
        for (int col = 0; col < crossword.numCols(); col++) {
            crossword[nextRow][col] = word[col];
        }

        /* See if that works. */
        if (canMakeCrosswordRec(crossword,
                                nextRow + 1,
                                rowWords, colWords)) {
            return true;
        }
    }

    /* Aw shucks. */
    return false;
}

/* Given a blank crossword, can it be filled in using English
 * words so that every square is filled?
 */
bool canMakeCrossword(Grid<char>& crossword,
                      const Lexicon& english) {
    Lexicon rowWords, colWords;
    for (string word: english) {
        if (word.length() == crossword.numCols()) {
            rowWords += word;
        }
        if (word.length() == crossword.numRows()) {
            colWords += word;
        }
    }
    return canMakeCrosswordRec(crossword, 0,
                               rowWords, colWords);

}

int main() {
    Lexicon english("EnglishWords.txt");

    /* The dimensions here are arbitrary but give rise to some pretty cool words! */
    Grid<char> crossword(4, 7);

    cout << "Starting..." << endl << endl;

    if (canMakeCrossword(crossword, english)) {
        printCrossword(crossword);
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}
