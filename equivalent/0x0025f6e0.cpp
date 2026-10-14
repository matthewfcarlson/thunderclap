// STATUS: equivalent (tools/equiv.py level 3: 880 inputs, branch coverage 24/24)
// FUN_0025f6e0 @ 0x0025f6e0
struct Node { Node* left; Node* right; Node* parent; unsigned color; };
struct Tree_25f6e0 { Node* root; Node sentinel; };
struct Entry_25f6e0 { unsigned data; Node node; };
extern Node* __cdecl FUN_0025ed00(Tree_25f6e0*,Node*);
extern void __cdecl FUN_0025ed40(Tree_25f6e0*,Node*);
void __cdecl FUN_0025f6e0(Tree_25f6e0* tree, Entry_25f6e0* entry) {
 Node* z=&entry->node; Node* nil=&tree->sentinel;
 Node* y;
 if(z->left!=nil && z->right!=nil) y=FUN_0025ed00(tree,z); else y=z;
 Node* x=y->left;
 if(x==nil) x=y->right;
 x->parent=y->parent;
 Node* p=y->parent;
 if(p==nil) tree->root=x;
 else if(p->left==y) p->left=x;
 else p->right=x;
 bool black=y->color==0;
 if(y!=z) {
 y->parent=z->parent;
 y->left=z->left;
 y->right=z->right;
 y->color=z->color;
 p=y->parent;
 if(p==nil) tree->root=y;
 else if(p->left==z) p->left=y;
 else p->right=y;
 if(y->left!=nil) y->left->parent=y;
 if(y->right->parent!=nil) y->right->parent=y;
 }
 if(black) FUN_0025ed40(tree,x);
}
