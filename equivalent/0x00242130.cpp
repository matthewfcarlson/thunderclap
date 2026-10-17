// STATUS: equivalent (tools/equiv.py level 3: 539 inputs, branch coverage 14/14)
// FUN_00242130 @ 0x00242130
struct TreeLink { TreeLink *left; TreeLink *parent; TreeLink *right; };
struct TreeNode { int value; TreeLink link; };

TreeNode *__cdecl FUN_00242130(TreeNode *head, TreeNode *current)
{
    TreeLink *sentinel = &head->link;
    TreeLink *node = current->link.parent;
    if (node != sentinel) {
        TreeLink *left = node->left;
        while (left != sentinel) {
            node = left;
            left = node->left;
        }
    } else {
        TreeLink *cursor = &current->link;
        node = cursor->right;
        while (node != sentinel && cursor == node->parent) {
            cursor = node;
            node = node->right;
        }
    }
    if (node == sentinel) return 0;
    return (TreeNode *)((char *)node - 4);
}