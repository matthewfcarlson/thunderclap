// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 11/12, incomplete)
// FUN_00304cb0 @ 0x00304cb0
// 0x00304cb0: depth-first search for the slot index of `target` below `node`; -1 when not found
#include "compat/ptr.h"
struct Node;
struct ChildList_304cb0 {
    Node** begin;
    Node** end;
};

struct Node {
    char pad00[8];
    int slot;
    Node* match;
    char pad10[4];
    ChildList_304cb0* children;
};

class Finder_304cb0 {
public:
    int FUN_00304cb0(Node* node, Node* target);
};

int Finder_304cb0::FUN_00304cb0(Node* node, Node* target)
{
    if (node->match == target)
        return node->slot;
    ChildList_304cb0* list = node->children;
    if (list == 0)
        return -1;
    if (((hulk_intptr)list->end - (hulk_intptr)list->begin & ~3) == 0)
        return -1;
    for (unsigned int i = 0; i < (unsigned int)(node->children->end - node->children->begin); i++) {
        int r = FUN_00304cb0(node->children->begin[i], target);
        if (r >= 0)
            return r;
    }
    return -1;
}
