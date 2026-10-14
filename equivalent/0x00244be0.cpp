// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 28/32, incomplete)
// FUN_00244be0 @ 0x00244be0
struct Key2 {
    unsigned int lo, hi;
};

struct Node {
    Node *left;                // 0x00
    Node *right;               // 0x04
    char pad08[0x14 - 8];
    Key2 key;                  // 0x14
};

struct Info {
    char pad0[0x30];
    Key2 key;                  // 0x30
};

class Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Info *v8();
    Node node;                 // 0x04
};

struct Tree {
    Node *first;               // 0x00
    Node sentinel;             // 0x04
};

struct Query {
    Key2 primary;              // 0x00
    Key2 secondary;            // 0x08
};

static int Compare(const Key2 &a, const Key2 &b)
{
    if (a.hi < b.hi || (a.hi == b.hi && a.lo < b.lo))
        return -1;
    if (b.hi < a.hi || (b.hi == a.hi && b.lo < a.lo))
        return 1;
    return 0;
}

Object *__cdecl FUN_00244be0(Tree *tree, Query *query)
{
    Node *end = &tree->sentinel;
    Node *node = tree->first;
    while (node != end) {
        int c = Compare(query->primary, node->key);
        Object *obj = (Object *)((char *)node - 4);
        if (c == 0)
            c = Compare(query->secondary, obj->v8()->key);
        if (c < 0)
            node = node->left;
        else if (c == 0)
            return obj;
        else
            node = node->right;
    }
    return 0;
}
