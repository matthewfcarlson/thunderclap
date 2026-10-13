// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 34/34)
// FUN_00242860 @ 0x00242860
struct Source {
    char pad0[0x18];
    float f18;
    float f1c;
    char pad20[8];
    unsigned char disabled;
};

struct Modifier {
    char pad0[0x2c];
    float f2c;
    float f30;
};

struct Link;

struct Entry {
    char pad0[8];
    Link *next;
    char padC[4];
    Source *source;
    Modifier *modifier;
};

struct Link {
    Entry *entry() { return (Entry *)((char *)this - 8); }
};

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    char padC[4];
    Link *links;
    char pad14[0x20 - 0x14];
    float product0;
    float product1;
};

struct Tree {
    TreeNode *root;
    TreeNode nil;
};

void FUN_00242860(Tree *tree)
{
    TreeNode *nil = &tree->nil;
    TreeNode *node = tree->root;
    if (node == nil)
        return;
    while (node->left != nil)
        node = node->left;

    do {
        float a = 1.0f;
        float b = 1.0f;

        if (node->links != 0) {
            Entry *e = node->links->entry();
            while (e != 0) {
                Source *src = e->source;
                Modifier *mod = e->modifier;
                if (src->f1c >= 1.0f) {
                    b = b * ((src->f1c - 1.0f) * mod->f2c + 1.0f);
                } else {
                    b = b * (1.0f - (1.0f - src->f1c) * mod->f2c);
                }
                float x;
                if (src->disabled == 0)
                    x = src->f18;
                else
                    x = 0.0f;
                float m = x + (1.0f - src->f18) * (1.0f - mod->f30);
                a = a * (m + (1.0f - mod->f2c) * (1.0f - m));
                e = e->next ? e->next->entry() : 0;
            }
        }
        node->product0 = a;
        node->product1 = b;

        TreeNode *s = node->right;
        if (s == nil) {
            TreeNode *child = node;
            s = node->parent;
            while (s != nil && child == s->right) {
                child = s;
                s = s->parent;
            }
        } else {
            while (s->left != nil)
                s = s->left;
        }
        node = s;
    } while (node != nil && node != 0);
}
