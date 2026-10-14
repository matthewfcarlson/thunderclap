// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 26/26)
// om::MetaType::vfunc_2 @ 0x0025f8f0
struct Node {
    Node *left;
    Node *right;
    Node *parent;
};

class Item_25f8f0 {
public:
    virtual void v0();
    virtual void v1();
    virtual bool Visit(int a, int b);
    Node node;          // 4
};

namespace om {

class MetaType {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual bool vfunc_2(int a, int b);
    char pad04[0x10];
    Node *root;         // 0x14
    Node nil;           // 0x18
};

static Item_25f8f0 *ItemOf(Node *n, Node *nil)
{
    return n == nil ? 0 : (Item_25f8f0 *)((char *)n - 4);
}

bool MetaType::vfunc_2(int a, int b)
{
    // in-order walk over the item tree
    Node *n = root;
    Item_25f8f0 *it;
    if (n == &nil) {
        it = 0;
    } else {
        while (n->left != &nil)
            n = n->left;
        it = (Item_25f8f0 *)((char *)n - 4);
    }
    while (it != 0) {
        if (!it->Visit(a, b))
            return false;
        Node *cur = &it->node;
        Node *next = cur->right;
        if (next != &nil) {
            while (next->left != &nil)
                next = next->left;
        } else {
            Node *p = cur->parent;
            while (p != &nil && cur == p->right) {
                cur = p;
                p = p->parent;
            }
            next = p;
        }
        it = ItemOf(next, &nil);
    }
    return true;
}

}
