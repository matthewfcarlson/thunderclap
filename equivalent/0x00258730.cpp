// STATUS: equivalent (tools/equiv.py level 3: 776 inputs, branch coverage 24/24)
// FUN_00258730 @ 0x00258730
struct Node { Node* left; Node* right; Node* parent; int color; };
struct Tree { Node* root; Node sentinel; };
struct Entry { char pad[8]; Node node; };
Node* __cdecl FUN_002581f0(Tree*, Node*);
void __cdecl FUN_00258230(Tree*, Node*);
void __cdecl FUN_00258730(Tree* tree, Entry* entry) {
 Node* sentinel = &tree->sentinel;
 Node* node = &entry->node;
 Node* removed = node;
 if (node->left != sentinel && node->right != sentinel)
  removed = FUN_002581f0(tree, node);
 Node* child = removed->left;
 if (child == sentinel) child = removed->right;
 child->parent = removed->parent;
 Node* parent = removed->parent;
 if (parent == sentinel) tree->root = child;
 else if (parent->left == removed) parent->left = child;
 else parent->right = child;
 bool black = removed->color == 0;
 if (removed != node) {
  removed->parent = node->parent;
  removed->left = node->left;
  removed->right = node->right;
  removed->color = node->color;
  parent = removed->parent;
  if (parent == sentinel) tree->root = removed;
  else if (parent->left == node) parent->left = removed;
  else parent->right = removed;
  if (removed->left != sentinel) removed->left->parent = removed;
  if (removed->right->parent != sentinel) removed->right->parent = removed;
 }
 if (black) FUN_00258230(tree, child);
}
