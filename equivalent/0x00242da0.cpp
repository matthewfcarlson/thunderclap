// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 30/30)
// FUN_00242da0 @ 0x00242da0
inline void *operator new(unsigned int, void *p) throw() { return p; }

struct Node {
    Node *left;
    Node *right;
    Node *parent;
};

struct Tree_242da0 {
    Node *root;
    Node nil;
};

struct Link_242da0 {
    Link_242da0 *next;
    Link_242da0 *prev;
};

struct Target_242da0;
struct Group;

struct Entry_242da0;

// One binding of an entry to a target, kept in both the target's and the group's list.
struct Binding_242da0 {
    Link_242da0 groupLink;
    Link_242da0 targetLink;
    Entry_242da0 *entry;
    Group *group;
    Target_242da0 *target;

    Binding_242da0() throw()
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

struct Target_242da0 {
    char pad00[0x10];
    Link_242da0 *head;
    Link_242da0 *tail;
};

struct Entry_242da0 {
    int vptr;
    Node node;
    char pad10[4];
    int key;
};

struct Owner_242da0 {
    char pad00[0x38];
    Tree_242da0 tree;
};

struct Group {
    char pad00[0x18];
    Link_242da0 *head;
    Link_242da0 *tail;
    Owner_242da0 *owner;
};

struct Context;

extern Target_242da0 *__cdecl FUN_00242ce0(Context *ctx, int *key);
extern void *__cdecl FUN_00247530(void *pool);
extern char DAT_004e5e40[];

static Entry_242da0 *EntryOf(Node *n)
{
    return (Entry_242da0 *)((char *)n - 4);
}

void FUN_00242da0(Context *ctx, Group *group)
{
    Owner_242da0 *owner = group->owner;
    Node *nil = &owner->tree.nil;
    Entry_242da0 *e;
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
        Target_242da0 *target = FUN_00242ce0(ctx, &e->key);
        Binding_242da0 *b = (Binding_242da0 *)FUN_00247530(DAT_004e5e40);
        if (b)
            new (b) Binding_242da0;
        b->target = target;
        b->group = group;
        b->entry = e;

        Link_242da0 *tl = &b->targetLink;
        if (target->head == 0) {
            target->head = tl;
            tl->prev = 0;
        } else {
            target->tail->next = tl;
            tl->prev = target->tail;
        }
        target->tail = tl;
        tl->next = 0;

        Link_242da0 *gl = &b->groupLink;
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
