// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 30/30)
// FUN_00242da0 @ 0x00242da0
inline void *operator new(unsigned int, void *p) throw() { return p; }

struct Node {
    Node *left;
    Node *right;
    Node *parent;
};

struct Tree {
    Node *root;
    Node nil;
};

struct Link {
    Link *next;
    Link *prev;
};

struct Target;
struct Group;

struct Entry;

// One binding of an entry to a target, kept in both the target's and the group's list.
struct Binding {
    Link groupLink;
    Link targetLink;
    Entry *entry;
    Group *group;
    Target *target;

    Binding() throw()
    {
        groupLink.next = 0;
        groupLink.prev = 0;
        targetLink.next = 0;
        targetLink.prev = 0;
        entry = 0;
        group = 0;
        target = 0;
    }
};

struct Target {
    char pad00[0x10];
    Link *head;
    Link *tail;
};

struct Entry {
    int vptr;
    Node node;
    char pad10[4];
    int key;
};

struct Owner {
    char pad00[0x38];
    Tree tree;
};

struct Group {
    char pad00[0x18];
    Link *head;
    Link *tail;
    Owner *owner;
};

struct Context;

extern Target *__cdecl FUN_00242ce0(Context *ctx, int *key);
extern void *__cdecl FUN_00247530(void *pool);
extern char DAT_004e5e40[];

static Entry *EntryOf(Node *n)
{
    return (Entry *)((char *)n - 4);
}

void FUN_00242da0(Context *ctx, Group *group)
{
    Owner *owner = group->owner;
    Node *nil = &owner->tree.nil;
    Entry *e;
    if (owner->tree.root == nil) {
        e = 0;
    } else {
        Node *n = owner->tree.root;
        while (n->left != nil)
            n = n->left;
        e = EntryOf(n);
    }
    if (!e)
        return;
    do {
        Target *target = FUN_00242ce0(ctx, &e->key);
        Binding *b = (Binding *)FUN_00247530(DAT_004e5e40);
        if (b)
            new (b) Binding;
        b->target = target;
        b->group = group;
        b->entry = e;

        Link *tl = &b->targetLink;
        if (target->head == 0) {
            target->head = tl;
            tl->prev = 0;
        } else {
            target->tail->next = tl;
            tl->prev = target->tail;
        }
        target->tail = tl;
        tl->next = 0;

        Link *gl = &b->groupLink;
        if (group->head == 0) {
            group->head = gl;
            gl->prev = 0;
        } else {
            group->tail->next = gl;
            gl->prev = group->tail;
        }
        group->tail = gl;
        gl->next = 0;

        // in-order successor
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
        e = next == nil ? 0 : EntryOf(next);
    } while (e != 0);
}
