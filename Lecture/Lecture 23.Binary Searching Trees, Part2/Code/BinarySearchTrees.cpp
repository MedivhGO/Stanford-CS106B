/*****************************************************
 * File: BinarySearchTrees.cpp
 *
 * A program to play around with binary search trees!
 */
#include <iostream>
#include <string>
#include "simpio.h"
#include "console.h"
using namespace std;

/* Type: Node
 * A node in a binary search tree.
 */
struct Node {
    string value;
    Node* left;
    Node* right;
};

bool contains(Node* root, const string& key) {
    /* Base case: If the tree is empty, your key isn't here. */
    if (root == nullptr) return false;

    /* Recursive case: See how we compare to the root. */
    if (key == root->value) return true;
    else if (key < root->value) return contains(root->left, key);
    else /*  key > root->value */ return contains(root->right, key);
}

void printContentsOf(Node* root) {
    /* Base case: Empty tree has nothing to print. */
    if (root == nullptr) return;

    /* Otherwise, print things in sorted order! To do that, we need to
     *
     *   1. print the smaller elements in sorted order,
     *   2. then print our value,
     *   3. then print the larger values in sorted order.
     */
    printContentsOf(root->left);
    cout << root->value << endl;
    printContentsOf(root->right);
}

void insertInto(Node*& root, const string& key) {
    /* Base case: If we insert into an empty tree, just make a new node for the key. */
    if (root == nullptr) {
        root = new Node { key, nullptr, nullptr };
    }
    /* Otherwise, see where we go. */
    else if (key < root->value) {
        insertInto(root->left, key);
    } else if (key > root->value) {
        insertInto(root->right, key);
    } /* else if (key == root->value) // do nothing */
}

/* Returns a BST containing a bunch of California trees. Normally, you wouldn't construct
 * a BST this way; this is just here for the lecture demo.
 */
Node* makeTreeTree() {
    return new Node {
        "Douglas Fir",
        new Node {
            "Bristlecone Pine",
            new Node {
                "Bay Laurel",
                nullptr,
                nullptr
            },
            new Node {
                "Coast Redwood",
                nullptr,
                nullptr
            }
        },
        new Node {
            "Jeffrey Pine",
            new Node {
                "Giant Sequoia",
                nullptr,
                nullptr
            },
            new Node {
                "Manzanita",
                nullptr,
                nullptr
            }
        }
    };
}

/* Deletes all the nodes in a tree. This approach uses a postorder traversal;
 * we delete the children before deleting the node itself.
 */
void deleteTree(Node* root) {
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

/* Finds all elements in the tree within a given range, printing them in
 * sorted order.
 */
void printInRange(Node* root, const string& low, const string& high) {
    /* Empty trees don't have anything in any range. */
    if (root == nullptr) return;

    /* If the range is purely to the left, just look there. */
    if (high < root->value) {
        printInRange(root->left, low, high);
    }
    /* If the range is purely to the right, just look there. */
    else if (root->value < low) {
        printInRange(root->right, low, high);
    }
    /* Otherwise, we're in the range, and so we need to print ourselves.
     * But there might also be other matches, and we'll need to find those
     * as well!
     */
    else {
        printInRange(root->left, low, high);
        cout << root->value << endl;
        printInRange(root->right, low, high);
    }
}

int main() {
    Node* root = makeTreeTree();
    insertInto(root, "Joshua Tree");
    insertInto(root, "Ponderosa Pine");

    printInRange(root, "C", "J");
    deleteTree(root);
    return 0;
}
