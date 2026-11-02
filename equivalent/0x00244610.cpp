// STATUS: equivalent (tools/equiv.py level 3: 1043 inputs, branch coverage 24/24)
// FUN_00244610 @ 0x00244610
struct Node { Node *left; Node *right; Node *parent; unsigned color; };
struct Tree_244610 { Node *root; Node sentinel; };
struct Object { char padding[0x48]; Node node; };
Node *__cdecl FUN_00243720(Tree_244610 *, Node *);
extern "C" void __cdecl FUN_00243760(void *, void *);
extern "C" void __cdecl FUN_00244610(void * tree_, void * object_)
{
    Tree_244610 * tree = (Tree_244610 *)tree_;
    Object * object = (Object *)object_;
    Node *nil = &tree->sentinel;
    Node *removed = &object->node;
    Node *replacement = removed;
    if (removed->left != nil && removed->right != nil)
        replacement = FUN_00243720(tree, removed);
    Node *child = replacement->left;
    if (child == nil)
        child = replacement->right;
    child->parent = replacement->parent;
    Node *parent = replacement->parent;
    if (parent == nil)
        tree->root = child;
    else if (parent->left == replacement)
        parent->left = child;
    else
        parent->right = child;
    bool fix = replacement->color == 0;
    if (replacement != removed) {
        replacement->parent = removed->parent;
        replacement->left = removed->left;
        replacement->right = removed->right;
        replacement->color = removed->color;
        parent = replacement->parent;
        if (parent == nil)
            tree->root = replacement;
        else if (parent->left == removed)
            parent->left = replacement;
        else
            parent->right = replacement;
        if (replacement->left != nil)
            replacement->left->parent = replacement;
        if (replacement->right->parent != nil)
            replacement->right->parent = replacement;
    }
    if (fix)
        FUN_00243760((Tree_244610 *)tree, (Node *)child);
}
