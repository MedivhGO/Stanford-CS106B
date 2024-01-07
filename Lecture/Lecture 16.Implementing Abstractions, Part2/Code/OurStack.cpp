#include "OurStack.h"
#include "error.h"

/* Constant controlling the default size of our stack. */
const int kInitialSize = 4;

/* Constructor initializes the fields of the stack to
 * appropriate defaults.
 */
OurStack::OurStack() {
    logicalSize = 0;
    allocatedSize = kInitialSize;
    elems = new int[allocatedSize];
}

/* Destructor cleans up memory allocated by the stack. */
OurStack::~OurStack() {
    delete[] elems;
}

int OurStack::size() const {
    return logicalSize;
}

bool OurStack::isEmpty() const {
    return size() == 0;
}

void OurStack::push(int value) {
    /* Out of space? */
    if (allocatedSize == logicalSize) {
        grow();
    }
    elems[logicalSize] = value;
    logicalSize++;
}

int OurStack::peek() const {
    if (isEmpty()) {
        error("What is the sound of one hand clapping?");
    }

    return elems[logicalSize - 1];
}

int OurStack::pop() {
    int result = peek();
    logicalSize--;
    return result;
}

void OurStack::grow() {
    /* Reserve more space. Doubling is a good balance between using more
     * space than needed and doing less total work. You often see 3/2
     * used in practice here.
     */
    allocatedSize *= 2;
    int* helper = new int[allocatedSize];

    /* Move everything over. (Technically, *copy* everything over.) */
    for (int i = 0; i < logicalSize; i++) {
        helper[i] = elems[i];
    }

    /* Get rid of our old array. */
    delete[] elems;
    
    /* Start using the new one! */
    elems = helper;
}
