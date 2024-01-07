/*********************************************************
 * File: OurStack.h
 *
 * A class representing a stack that holds integers.
 */
#pragma once

class OurStack {
public:
    /* Constructor initializes the fields to reasonable values. */
    OurStack();

    /* Destructor cleans up all allocated memory. */
    ~OurStack();

    void push(int value);
    int  pop();
    int  peek() const;

    bool isEmpty() const;
    int  size() const;

private:
    int* elems;         // The actual array of elements.
    int  allocatedSize; // How much space is allocated in our stack.
    int  logicalSize;   // How many elements are logically in the stack.

    void grow();        // Creates a larger array to hold our elements.
};


