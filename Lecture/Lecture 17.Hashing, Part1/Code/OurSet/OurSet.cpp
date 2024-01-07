#include "OurSet.h"
using namespace std;

const int kInitialBucketCount = 6; // Or really anything, really.
const double kMaxLoadFactor = 2;

/********************************************
 * private:
 *    Vector<Vector<string>> buckets;
 *    HashFunction<string> hashFn;
 *    int numElems;
 */
OurSet::OurSet() {
    Vector<Vector<string>> ourBuckets(kInitialBucketCount);
    HashFunction<string> ourHashFn(kInitialBucketCount);

    buckets = ourBuckets;
    hashFn  = ourHashFn;
    numElems = 0;
}

int OurSet::size() const {
    return numElems;
}

bool OurSet::isEmpty() const {
    return size() == 0;
}

/* Jump to the right bucket, then see if that bucket has our
 * element.
 */
bool OurSet::contains(const string& str) const {
    int bucket = hashFn(str);
    for (string elem: buckets[bucket]) {
        if (elem == str) return true;
    }
    return false;
}

void OurSet::add(const string& str) {
    /* No duplicates. */
    if (contains(str)) return;

    /* Add this to the correct bucket. */
    int bucket = hashFn(str);
    buckets[bucket] += str;
    numElems++;

    /* If our load factor exceeds the maximum, rehash. */
    if (double(numElems) / buckets.size() > kMaxLoadFactor) {
        rehash();
    }
}

void OurSet::rehash() {
    /* We need new buckets and a new hash function, since our old hash
     * function is designed to only work on a smaller range.
     */
    Vector<Vector<string>> newBuckets(buckets.size() * 2);
    HashFunction<string> newHashFn(buckets.size() * 2);

    /* Redistribute all elements into the new buckets. */
    for (int i = 0; i < buckets.size(); i++) {
        for (string elem: buckets[i]) {
            int newBucket = newHashFn(elem);
            newBuckets[newBucket] += elem;
        }
    }

    /* Update master list of buckets and our hash function. */
    buckets = newBuckets;
    hashFn = newHashFn;
}




