// STATUS: equivalent (tools/equiv.py level 3: 2947 inputs, branch coverage 24/24)
// FUN_002603e0 @ 0x002603e0
#include "decls/data/records.h"
// The tree of sequence event types (records.h: OmTree of SeqEventTypeHead entries).
typedef OmTreeNode Node_2603e0;
Node_2603e0 *__cdecl FUN_0025fe80(OmTree *, Node_2603e0 *);
struct SeqEventTree_2603e0 {     // class scope: FUN_0025fec0 is a C definition of this TU (gen_tree)
    static void __cdecl FUN_0025fec0(void *, void *);
};
extern "C" void __cdecl FUN_002603e0(void * tree_, void * item_) {
    OmTree * tree = (OmTree *)tree_;
    SeqEventTypeHead * item = (SeqEventTypeHead *)item_;
 Node_2603e0 *s = &item->node;
 Node_2603e0 *nil = &tree->nil;
 Node_2603e0 *n;
 if (s->left != nil && s->right != nil) n = FUN_0025fe80(tree,s);
 else n = s;
 Node_2603e0 *child = n->left;
 if (child == nil) child = n->right;
 child->parent = n->parent;
 Node_2603e0 *p = n->parent;
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
 Node_2603e0 *l = n->left;
 if (l != nil) l->parent = n;
 Node_2603e0 *r = n->right;
 if (r->parent != nil) r->parent = n;
 }
 if (black) SeqEventTree_2603e0::FUN_0025fec0((OmTree *)tree,(Node_2603e0 *)child);
}
