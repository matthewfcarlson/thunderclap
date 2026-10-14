// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000c5b80 @ 0x000c5b80
struct Node {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10();
 virtual int count();
 virtual Node* child(int index);
};
struct Entry_c5b80 { Node* node; int index; };
struct Walker_c5b80 {
 int reserved;
 Entry_c5b80 stack[128];
 int depth;
 Node* current;
 int index;
 Node* FUN_000c5b80();
};
Node* Walker_c5b80::FUN_000c5b80() {
 while (current) {
  int size = current->count();
  if (index < size) {
   ++depth;
   if (depth >= 128) return 0;
   stack[depth].node = current;
   stack[depth].index = index;
   Node* next = current->child(index);
   current = next;
   index = 0;
   return next;
  }
  current = stack[depth].node;
  int previous = stack[depth].index;
  index = previous;
  --depth;
  index = previous + 1;
 }
 return current;
}
