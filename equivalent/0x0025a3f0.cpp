// STATUS: equivalent (tools/equiv.py level 3: 2648 inputs, branch coverage 38/38)
// audio::Mix::vfunc_3 @ 0x0025a3f0
struct Writer {
    char pad0[0x24];
    int indent;
};

struct Archive {
    Writer *writer;
};

char FUN_00246f50(Writer *writer, const char *fmt, ...);
char FUN_0025abb0(Archive *ar, unsigned int value);
char FUN_0024eb60(Archive *ar, const char *name, unsigned int *value);

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

struct MixChild {
    virtual char save(Archive *ar);
    TreeNode node;
};

struct Tree {
    TreeNode *root;
    TreeNode nil;
};

namespace audio {

class Mix {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(Archive *ar);
    char pad04[0x30 - 4];
    unsigned int fadeInTimeMs;
    unsigned int fadeOutTimeMs;
    Tree children;
};

char Mix::vfunc_3(Archive *ar)
{
    if (!FUN_00246f50(ar->writer, "Version %u\n", 1))
        return 0;
    if (!FUN_00246f50(ar->writer, "%s ", "mFadeInTimeMs"))
        return 0;
    if (!FUN_0025abb0(ar, fadeInTimeMs))
        return 0;
    if (!FUN_00246f50(ar->writer, "\n"))
        return 0;
    if (!FUN_0024eb60(ar, "mFadeOutTimeMs", &fadeOutTimeMs))
        return 0;
    if (!FUN_00246f50(ar->writer, "[\n"))
        return 0;

    ar->writer->indent++;

    TreeNode *nil = &children.nil;
    TreeNode *node = children.root;
    if (node != nil) {
        while (node->left != nil)
            node = node->left;
        MixChild *child = (MixChild *)((char *)node - 4);
        while (child != 0) {
            if (!child->save(ar))
                return 0;

            TreeNode *s = child->node.right;
            if (s == nil) {
                TreeNode *c = &child->node;
                s = c->parent;
                while (s != nil && c == s->right) {
                    c = s;
                    s = s->parent;
                }
            } else {
                while (s->left != nil)
                    s = s->left;
            }
            if (s == nil)
                break;
            child = (MixChild *)((char *)s - 4);
        }
    }

    ar->writer->indent--;
    return FUN_00246f50(ar->writer, "]\n") != 0;
}

}
