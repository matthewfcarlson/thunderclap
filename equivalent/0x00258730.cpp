// STATUS: equivalent (tools/equiv.py level 3: 2941 inputs, branch coverage 24/24)
// FUN_00258730 @ 0x00258730
#include "decls/data/records.h"
// The tree of om types by key (records.h OmType's node; 0x004cd1a8 is an OmTree without the count).
OmTreeNode* __cdecl FUN_002581f0(OmTree*, OmTreeNode*);
extern "C" void FUN_00258230(void *, void *);
void __cdecl FUN_00258730(OmTree* tree, OmType* entry) {
 OmTreeNode* sentinel = &tree->nil;
 OmTreeNode* node = &entry->body.node;
 OmTreeNode* removed = node;
 if (node->left != sentinel && node->right != sentinel)
  removed = FUN_002581f0(tree, node);
 OmTreeNode* child = removed->left;
 if (child == sentinel) child = removed->right;
 child->parent = removed->parent;
 OmTreeNode* parent = removed->parent;
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
