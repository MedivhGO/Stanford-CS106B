/*************************************************
 * File: LinkedLists.cpp
 *
 * Our very second program using Linked Lists! :-D
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

/* Given a linked list, how long is it? */
int lengthOf(Cell* list) {
    /* Base case: An empty list has length zero. */
    if (list == nullptr) return 0;

    /* Recursive case: The length is one, plus the length of the
     * remaining list.
     */
    return 1 + lengthOf(list->next);
}

/* From last time! */
void printList(Cell* list) {
    while (list != nullptr) {
        cout << list->value << endl;
        list = list->next;
    }
}

/* From last time! */
void deleteList(Cell* list) {
    while (list != nullptr) {
        Cell* next = list->next;
        delete list;
        list = next;
    }
}

/* Prepends the given value to the linked list. We take the list parameter by
 * reference because we intend to change where it points.
 */
void prependTo(Cell*& list, const string& value) {
    Cell* cell = new Cell;
    cell->value = value;
    
    /* After the new cell is the existing list. */
    cell->next = list;
    
    /* The list now starts with this cell. */
    list = cell; 
}

/* Appends the given value to the list. This function uses both a head and tail
 * pointer to make things Lightning Fast.
 */
void appendTo(Cell*& list, Cell*& tail, const string& value) {
    Cell* cell = new Cell;
    cell->value = value;
    
    /* New cell goes at the end. */
    cell->next = nullptr;
    
    /* Case 1: The list is empty. */
    if (list == nullptr) {
        list = tail = cell;
    }
    /* Case 2: There's a cell already there. */
    else {
        /* The last element of the list should point to the new item. */
        tail->next = cell;
        
        /* That new item is now the last cell in the list. */
        tail = cell;
    }
}

int main() {
    Cell* list = nullptr;
    Cell* tail = nullptr;

    appendTo(list, tail, "Elephant");
    appendTo(list, tail, "Sunfish");
    appendTo(list, tail, "Whale");
    appendTo(list, tail, "Piraracu");

    printList(list);
    
    /* Great question to ponder: Why DON'T we say 'delete tail;' here? */
    deleteList(list);
    return 0;
}






