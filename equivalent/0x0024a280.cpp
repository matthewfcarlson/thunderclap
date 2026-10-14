// STATUS: equivalent (tools/equiv.py level 3: 129 inputs, branch coverage 41/42, incomplete)
// FUN_0024a280 @ 0x0024a280
struct Node {
    Node *left;
    Node *right;
    Node *parent;
};

struct Tree {
    Node *root;
    Node nil;
};

class Owner;

// An entry is an object whose tree node sits at offset 4, right after the vptr.
class Entry {
public:
    virtual ~Entry() throw();
    virtual bool vfunc_1(Owner *owner, int arg);
    Node node;
};

extern void __cdecl FUN_00249c20(Tree *tree, Entry *entry);

static Entry *EntryOf(Node *n)
{
    return (Entry *)((char *)n - 4);
}

class Owner {
public:
    char pad00[0x14];
    Tree tree;

    void FUN_0024a280(int arg);
};

// Calls every entry's callback in tree order and removes and deletes the ones that return true.
void Owner::FUN_0024a280(int arg)
{
    Node *nil = &tree.nil;
    Node *n = tree.root;
    if (n == nil)
        return;
    while (n->left != nil)
        n = n->left;
    Entry *e = EntryOf(n);
    if (!e)
        return;
    do {
        bool remove = e->vfunc_1(this, arg);

        // in-order successor of e->node
        Node *cur = &e->node;
        Node *next = cur->right;
        if (next == nil) {
            next = cur->parent;
            while (next != nil && cur == next->right) {
                cur = next;
                next = next->parent;
            }
        } else {
            while (next->left != nil)
                next = next->left;
        }
        Entry *following = next == nil ? 0 : EntryOf(next);

        if (remove) {
            FUN_00249c20(&tree, e);
            if (e)
                delete e;
        }
        e = following;
    } while (e);
}
