// STATUS: equivalent (tools/equiv.py level 3: 54 inputs, branch coverage 12/12)
// FUN_00242ce0 @ 0x00242ce0
#include "decls/data/engine/unknown.h"

struct Node {
    Node* left;
    Node* right;
    char pad[8];
    int v10, v14;
    unsigned key;
    int refs;
    float v20, v24;
};
struct Map_242ce0 { Node* root; };
Node* __cdecl FUN_00247530(void* heap);
void __cdecl FUN_00242a00(Map_242ce0* map, Node* node, unsigned* key);
Node* FindOrInsert(Map_242ce0* map, const unsigned* key) {
    Node* nil = (Node*)((char*)map + 4);
    Node* n = map->root;
    Node* volatile hit = 0;
    if (n != nil) {
        unsigned k = *key;
        do {
            if (k < n->key) {
                n = n->left;
            } else if (k <= n->key) {
                hit = n;
                break;
            } else {
                n = n->right;
            }
        } while (n != nil);
    }
    if (hit) {
        hit->refs++;
        return hit;
    }
    Node* alloc = FUN_00247530(DAT_004e5e88);
    Node* node = 0;
    if (alloc) {
        alloc->v10 = 0;
        alloc->v14 = 0;
        node = alloc;
    }
    node->v20 = 1.0f;
    node->v24 = 1.0f;
    node->key = *key;
    FUN_00242a00(map, node, &node->key);
    node->refs = 1;
    return node;
}
