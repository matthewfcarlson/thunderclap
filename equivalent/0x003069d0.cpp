// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 18/18)
// FUN_003069d0 @ 0x003069d0
struct Node;
struct Children { Node** begin; Node** end; };
struct Node {
 virtual void slot0();
 virtual void slot1();
 char pad[16];
 Children* children;
 bool FUN_003069d0(Node* target);
};
bool Node::FUN_003069d0(Node* target) {
 Children* list = children;
 bool result = false;
 if (list) {
  unsigned count = (unsigned)(list->end - list->begin);
  for (unsigned i=0; i<count; ++i) {
   if (list->begin[i] == target) {
    Node** pos = list->begin+i;
    if (pos) {
     Node** end = list->end;
     for (Node** next=pos+1; next!=end; ++next) next[-1]=*next;
     --list->end;
     target->slot1();
     return true;
    }
    break;
   }
   count = (unsigned)(list->end-list->begin);
  }
  for (unsigned i=0; i<(unsigned)(list->end-list->begin); ++i) {
   result = list->begin[i]->FUN_003069d0(target);
   list = children;
  }
 }
 return result;
}