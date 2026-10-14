// STATUS: equivalent (tools/equiv.py level 3: 704 inputs, branch coverage 24/24)
// FUN_00230de0 @ 0x00230de0
struct Node { Node* left; Node* right; Node* parent; unsigned char color; char padding[3]; };
struct Tree {
 Node* root;
 Node sentinel;
 unsigned int count;
 Node* FUN_00230800(Node* node);
 void FUN_00230900(Node* node);
 void FUN_00230de0(Node* node);
};
void Tree::FUN_00230de0(Node* node) {
 Node* nil = &sentinel;
 Node* removed;
 if (node->left != nil && node->right != nil) removed = FUN_00230800(node);
 else removed = node;
 Node* child = removed->left;
 if (child == nil) child = removed->right;
 child->parent = removed->parent;
 Node* parent = removed->parent;
 if (parent == nil) root = child;
 else if (parent->left == removed) parent->left = child;
 else parent->right = child;
 bool black = removed->color == 0;
 if (removed != node) {
  removed->parent = node->parent;
  removed->left = node->left;
  removed->right = node->right;
  removed->color = node->color;
  parent = removed->parent;
  if (parent == nil) root = removed;
  else if (parent->left == node) parent->left = removed;
  else parent->right = removed;
  if (removed->left != nil) removed->left->parent = removed;
  if (removed->right->parent != nil) removed->right->parent = removed;
 }
 if (black) FUN_00230900(child);
 --count;
}
