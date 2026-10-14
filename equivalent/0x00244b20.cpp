// STATUS: equivalent (tools/equiv.py level 3: 880 inputs, branch coverage 24/24)
// FUN_00244b20 @ 0x00244b20
struct Node { Node* left; Node* right; Node* parent; unsigned color; };
struct Tree { Node* root; Node sentinel; };
struct Entry { unsigned data; Node links; };
Node* __cdecl FUN_00243d30(Tree*, Node*);
Node* __cdecl FUN_00243d70(Tree*, Node*);
Node* __cdecl FUN_00244b20(Tree* tree, Entry* entry) {
 Node* sentinel = &tree->sentinel;
 Node* removed = &entry->links;
 Node* node = removed;
 if (removed->left != sentinel && removed->right != sentinel) node = FUN_00243d30(tree, removed);
 Node* child = node->left;
 if (child == sentinel) child = node->right;
 child->parent = node->parent;
 Node* parent = node->parent;
 if (parent == sentinel) tree->root = child;
 else if (parent->left == node) parent->left = child;
 else parent->right = child;
 bool black = node->color == 0;
 if (node != removed) {
  node->parent = removed->parent;
  node->left = removed->left;
  node->right = removed->right;
  node->color = removed->color;
  parent = node->parent;
  if (parent == sentinel) tree->root = node;
  else if (parent->left == removed) parent->left = node;
  else parent->right = node;
  if (node->left != sentinel) node->left->parent = node;
  if (node->right->parent != sentinel) node->right->parent = node;
 }
 if (black) return FUN_00243d70(tree, child);
 return node;
}