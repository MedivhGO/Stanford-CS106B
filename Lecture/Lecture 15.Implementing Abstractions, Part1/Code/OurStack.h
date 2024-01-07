/*********************************************************
 * File: OurStack.h
 *
 * A class representing a stack that holds integers.
 */
#pragma once

class OurStack {
public:
    OurStack();
    ~OurStack();

    void push(int value);
    int  pop();
    int  peek() const;

    int  size() const;
    bool isEmpty() const;

private:
    int* elems;         // Pointer to the array of elements
    int  allocatedSize; // How much space has been allocated
    int  logicalSize;   // How much space has been used
};

