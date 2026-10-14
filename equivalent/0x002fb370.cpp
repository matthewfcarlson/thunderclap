// STATUS: equivalent (tools/equiv.py level 3: 277 inputs, branch coverage 12/12)
// FUN_002fb370 @ 0x002fb370
struct Node;
struct Children { Node** begin; Node** end; };
struct Node {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual int kind();
 char padding[16]; Children* children;
};
struct Handler {
 bool FUN_002fa8c0(Node*, void*, void*);
 bool FUN_002faa30(Node*, void*, void*);
 bool FUN_002fb000(Node*, void*, void*);
 bool FUN_002fb370(Node*, void*, void*);
};
bool Handler::FUN_002fb370(Node* node, void* arg, void* arg2) {
 bool result=false;
 Children* children=node->children;
 if(children) {
  unsigned int i=0;
  while(i < (unsigned int)(children->end-children->begin)) {
   result=FUN_002fb370(children->begin[i],arg,arg2);
   ++i;
  }
 }
 switch(node->kind()) {
 case 2: return FUN_002fa8c0(node,arg,arg2);
 case 5: return FUN_002faa30(node,arg,arg2);
 case 7: return FUN_002fb000(node,arg,arg2);
 }
 return result;
}
