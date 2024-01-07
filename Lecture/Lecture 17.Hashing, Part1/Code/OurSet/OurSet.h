#pragma once

#include <string>
#include "vector.h"
#include "HashFunction.h"

class OurSet {
public:
    OurSet();

    bool contains(const std::string& value) const;
    void add(const std::string& value);

    int  size() const;
    bool isEmpty() const;

private:
    /* List of buckets. Each bucket is a list of the strings in
     * that bucket.
     */
    Vector<Vector<std::string>> buckets;

    /* Hash function to distribute items into buckets. */
    HashFunction<std::string> hashFn;

    /* Total number of elements, different from number of buckets. */
    int numElems;

    /* Performs a rehash, doubling the number of buckets and choosing
     * a new hash function.
     */
    void rehash();
};

