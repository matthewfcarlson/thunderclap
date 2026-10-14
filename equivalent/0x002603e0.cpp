// STATUS: equivalent (tools/equiv.py level 3: 1043 inputs, branch coverage 24/24)
// FUN_002603e0 @ 0x002603e0
struct Node { Node *left; Node *right; Node *parent; int color; };
struct Tree_2603e0 { Node *root; Node sentinel; };
struct Item_2603e0 { char pad[0x48]; Node node; };
Node *__cdecl FUN_0025fe80(Tree_2603e0 *, Node *);
void __cdecl FUN_0025fec0(Tree_2603e0 *, Node *);
void __cdecl FUN_002603e0(Tree_2603e0 *tree, Item_2603e0 *item) {
 Node *s = &item->node;
 Node *nil = &tree->sentinel;
 Node *n;
 if (s->left != nil && s->right != nil) n = FUN_0025fe80(tree,s);
 else n = s;
 Node *child = n->left;
 if (child == nil) child = n->right;
 child->parent = n->parent;
 Node *p = n->parent;
 if (p == nil) tree->root = child;
 else if (p->left == n) p->left = child;
 else p->right = child;
 bool black = n->color == 0;
 if (n != s) {
 n->parent = s->parent;
 n->left = s->left;
 n->right = s->right;
 n->color = s->color;
 p = n->parent;
 if (p == nil) tree->root = n;
 else if (p->left == s) p->left = n;
 else p->right = n;
 Node *l = n->left;
 if (l != nil) l->parent = n;
 Node *r = n->right;
 if (r->parent != nil) r->parent = n;
 }
 if (black) FUN_0025fec0(tree,child);
}
