// STATUS: equivalent (tools/equiv.py level 3: 54 inputs, branch coverage 12/12)
// FUN_0024a940 @ 0x0024a940
#include "decls/data/engine/audio.h"

struct Node {
    Node* left;             // 0x00
    Node* right;            // 0x04
    char pad8[8];
    unsigned int key;       // 0x10
    Node* FUN_0024a510(unsigned int key);
};

struct Tree_24a940 {
    Node* root;             // 0x00
    Node nil;               // 0x04 (sentinel)
};

struct Map_24a940 {
    char pad0[0x48];
    Tree_24a940 tree;              // 0x48
};

Node* __cdecl FUN_00247530(char* pool);
void __cdecl FUN_00249ff0(Tree_24a940* tree, Node* node, const unsigned int* key);

// Finds the node for *key, creating and linking a new one when it is missing.
Node* FUN_0024a940(Map_24a940* map, const unsigned int* key)
{
    Tree_24a940* tree = &map->tree;
    Node* nil = &tree->nil;
    Node* n = tree->root;
    // volatile: keeps the null test on the hit, which MSVC otherwise drops because the node was dereferenced
    Node* volatile found = 0;
    unsigned int k = *key;
    while (n != nil) {
        if (k < n->key) {
            n = n->left;
        } else if (k <= n->key) {
            found = n;
            break;
        } else {
            n = n->right;
        }
    }
    if (found)
        return found;
    Node* mem = FUN_00247530(DAT_004e60c8);
    Node* created = 0;
    if (mem)
        created = mem->FUN_0024a510(*key);
    FUN_00249ff0(tree, created, key);
    return created;
}
