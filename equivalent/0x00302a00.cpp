// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 20/21, incomplete)
// FUN_00302a00 @ 0x00302a00
#include "decls/data/engine/unknown.h"

struct Node;

struct NodeList_302a00 {
    Node **begin;
    Node **end;
};

class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int type();
    char pad4[0x14 - 4];
    NodeList_302a00 *children;
};

struct Query_302a00 {
    char pad0[0xc];
    float limit;
};

union Slot_302a00 {
    Node *node;
    float best;
};

float FUN_003015c0(Node *node, int a3);
float FUN_003024d0(Node *node, int a3);
float FUN_00302620(Node *node, int a3);
float FUN_00302480(Node *node, int a3);


class Solver_302a00 {
public:
    char FUN_00302720(Query_302a00 *q, float v);
    char FUN_00302a00(Query_302a00 *q, Slot_302a00 arg, int a3);
};

char Solver_302a00::FUN_00302a00(Query_302a00 *q, Slot_302a00 arg, int a3)
{
    Node *node = arg.node;
    NodeList_302a00 *list = node->children;

    if (list != 0 && (((int)list->end - (int)list->begin) & ~3) != 0) {
        arg.best = DAT_004d2f14;
        unsigned int n = (unsigned int)(((int)list->end - (int)list->begin) >> 2);
        unsigned int i = 0;
        while (i < n) {
            Slot_302a00 child;
            child.node = node->children->begin[i];
            if (FUN_00302a00(q, child, a3) == 1)
                return 1;
            if (!(arg.best < q->limit))
                arg.best = q->limit;
            i++;
            n = (unsigned int)(((int)node->children->end - (int)node->children->begin) >> 2);
        }
        if (arg.best < q->limit)
            q->limit = arg.best;
        return 0;
    }

    float v;
    switch (node->type()) {
    case 2:
        v = FUN_00302620(node, a3);
        return FUN_00302720(q, v);
    case 5:
        v = FUN_003024d0(node, a3);
        return FUN_00302720(q, v);
    case 7:
        v = FUN_00302480(node, a3);
        return FUN_00302720(q, v);
    case 8:
        v = FUN_003015c0(node, a3);
        return FUN_00302720(q, v);
    default:
        return 0;
    }
}
