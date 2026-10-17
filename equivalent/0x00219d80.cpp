// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00219d80 @ 0x00219d80
#include "decls/data/engine/unknown.h"

struct Node {
    char unused[8];
    int value;
    char padding[4];
    Node *next;
};
Node * __cdecl FUN_002198b0(int key, int *list);
int __cdecl FUN_00215fa0(Node *node, int *list);
// equiv-conv: FUN_00219d80 edi stack
int * __cdecl FUN_00219d80(int *list, int key) {
    if (*list != 0) {
        Node *node = FUN_002198b0(key, list);
        do {
            if (FUN_00215fa0(node, list) != 0)
                return &node->value;
            node = node->next;
        } while (node != 0);
    }
    return ((int*)&DAT_00426824);
}
