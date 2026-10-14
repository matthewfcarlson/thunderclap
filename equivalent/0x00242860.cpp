// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 34/34)
// FUN_00242860 @ 0x00242860
struct Source_242860 {
    char pad0[0x18];
    float f18;
    float f1c;
    char pad20[8];
    unsigned char disabled;
};

struct Modifier_242860 {
    char pad0[0x2c];
    float f2c;
    float f30;
};

struct Link_242860;

struct Entry_242860 {
    char pad0[8];
    Link_242860 *next;
    char padC[4];
    Source_242860 *source;
    Modifier_242860 *modifier;
};

struct Link_242860 {
    Entry_242860 *entry() { return (Entry_242860 *)((char *)this - 8); }
};

struct TreeNode_242860 {
    TreeNode_242860 *left;
    TreeNode_242860 *right;
    TreeNode_242860 *parent;
    char padC[4];
    Link_242860 *links;
    char pad14[0x20 - 0x14];
    float product0;
    float product1;
};

struct Tree_242860 {
    TreeNode_242860 *root;
    TreeNode_242860 nil;
};

void FUN_00242860(Tree_242860 *tree)
{
    TreeNode_242860 *nil = &tree->nil;
    TreeNode_242860 *node = tree->root;
    if (node == nil)
        return;
    while (node->left != nil)
        node = node->left;

    do {
        float a = 1.0f;
        float b = 1.0f;

        if (node->links != 0) {
            Entry_242860 *e = node->links->entry();
            while (e != 0) {
                Source_242860 *src = e->source;
                Modifier_242860 *mod = e->modifier;
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

        TreeNode_242860 *s = node->right;
        if (s == nil) {
            TreeNode_242860 *child = node;
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
