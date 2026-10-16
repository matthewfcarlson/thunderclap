// STATUS: equivalent (tools/equiv.py level 3: 59 inputs, branch coverage 52/56, incomplete)
// FUN_0024a800 @ 0x0024a800
struct Context;

struct Sub {
    void FUN_0024a280(Context *ctx);
};

struct TreeLink {
    TreeLink *left;
    TreeLink *right;
    TreeLink *parent;
};

struct Flags {
    char pad00[0x44];
    unsigned char bits;
};

struct Entry {
    Entry *next;
    char pad04[0x3c - 4];
    short state;
};

struct ChildNode : TreeLink {
    char pad0c[0x50 - 0xc];
    Sub sub;
};

struct GroupNode : TreeLink {
    char pad0c[4];
    Entry *entries;
    char pad14[0x1c - 0x14];
    Flags *flags;
};

struct Scene;

// equiv-conv: FUN_00249630 stack edi
void __cdecl FUN_00249630(Context *ctx, Scene *scene);
// equiv-conv: FUN_0024a3c0 eax ecx stack stack
char __cdecl FUN_0024a3c0(Entry *entry, Scene *scene, GroupNode *group, Context *ctx);
// equiv-conv: FUN_00249750 esi
void __cdecl FUN_00249750(Entry *entry);

struct Scene {
    char pad00[0x18];
    GroupNode *groupRoot;
    TreeLink groupNil;
    char pad28[0x48 - 0x28];
    ChildNode *childRoot;
    TreeLink childNil;
    char pad58[0x5c - 0x58];
    Sub sub;
};

// In-order successor in a tree whose empty links point at the nil node.
static TreeLink *Successor(TreeLink *n, TreeLink *nil)
{
    if (n->right != nil) {
        TreeLink *c = n->right;
        while (c->left != nil)
            c = c->left;
        return c;
    }
    TreeLink *p = n->parent;
    while (p != nil && n == p->right) {
        n = p;
        p = p->parent;
    }
    return p;
}

void FUN_0024a800(Scene *scene, Context *ctx)
{
    scene->sub.FUN_0024a280(ctx);
    FUN_00249630(ctx, scene);

    TreeLink *childNil = &scene->childNil;
    TreeLink *node = scene->childRoot;
    if (node != childNil) {
        while (node->left != childNil)
            node = node->left;
        for (;;) {
            static_cast<ChildNode *>(node)->sub.FUN_0024a280(ctx);
            node = Successor(node, childNil);
            if (node == childNil || node == 0)
                break;
        }
    }

    TreeLink *groupNil = &scene->groupNil;
    node = scene->groupRoot;
    if (node != groupNil) {
        while (node->left != groupNil)
            node = node->left;
        for (;;) {
            GroupNode *group = static_cast<GroupNode *>(node);
            Entry *e = group->entries;
            while (e != 0) {
                if (FUN_0024a3c0(e, scene, group, ctx) && e->state == 0 && (group->flags->bits & 2) == 0) {
                    Entry *dead = e;
                    e = e->next;
                    FUN_00249750(dead);
                } else {
                    e = e->next;
                }
            }
            node = Successor(node, groupNil);
            if (node == groupNil || node == 0)
                break;
        }
    }
}
