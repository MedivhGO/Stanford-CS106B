/*************************************************
 * File: LinkedLists.cpp
 *
 * Our very first program using Linked Lists! :-D
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "console.h"
using namespace std;

/* Type: Cell
 *
 * A cell in a linked list.
 */
struct Cell {
    string value;
    Cell* next;
};

/* Given a linked list, returns how many cells are in that list.
 *
 * This is implemented recursively. Can you re=implement it iteratively?
 */
int lengthOf(Cell* list) {
    /* Base case: An empty list has length zero. */
    if (list == nullptr) return 0;

    /* Recursive case: A nonempty list has length one for the first cell,
     * plus how many other cells follow it.
     */
    return 1 + lengthOf(list->next);
}

/* Prints a list to the console. This is implemented iteratively - can you
 * rewrite it recursively?
 */
void printList(Cell* list) {
    while (list != nullptr) {
        cout << list->value << endl;
        list = list->next;
    }
}

/* Prompts the user to enter a list of values. then creates a linked list to
 * hold them.
 */
Cell* readList() {
    /* Get some text. */
    string text = getLine("Enter next value, or empty string if you're done: ");

    /* If the user just hit ENTER, they get an empty list. */
    if (text == "") return nullptr;

    /* Otherwise, they get a cell with this item in it, followed by a list
     * containing whatever they're going to enter next.
     */
    Cell* result  = new Cell;
    result->value = text;
    result->next  = readList();
    return result;
}

/* Cleans up all the memory used by a linked list. */
void deleteList(Cell* list) {
    while (list != nullptr) {
        /* We need this helper pointer to remember where we're going to
         * go next. Without it, we'd lose track of the next item in the
         * list as soon as we delete the first cell.
         */
        Cell* next = list->next;
        delete list;
        
        list = next;
    }
}

int main() {
    Cell* list = readList();

    cout << "The length of this list is " << lengthOf(list) << endl;
    printList(list);
    deleteList(list);

    return 0;
}










/* Things that give logarithms:
 *
 *   1. Repeatedly dividing by a constant.
 *
 *   n  -->   n/2   -->    n/4    -->   ...  ->  1
 *               O(log n) steps.
 *
 *
 *   2. Repeatedly multiplying by a constant
 *
 *   1  ->  2  ->  4  ->  8  -> ... -> n
 *               O(log n) steps.
 *
 *
 *
 *                *          O(n)
 *              /   \
 *            *       *      O(n)
 *           / \     / \
 *          *   *   *   *    O(n)
 *         / \ / \ / \ / \
 *         * * * * * * * *   O(n)
 *
 */




















