// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000f6460 @ 0x000f6460
struct Node {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10();
 virtual int count();
 virtual Node* child(int index);
};
struct Frame_f6460 { Node* node; int index; };
struct Traversal {
 int reserved;
 Frame_f6460 frames[128];
 int depth;
 Node* current;
 int index;
 Node* FUN_000f6460();
};
Node* Traversal::FUN_000f6460() {
 while (current) {
  int count = current->count();
  if (index < count) {
   ++depth;
   if (depth >= 128) return 0;
   frames[depth].node = current;
   frames[depth].index = index;
   Node* result = current->child(index);
   current = result;
   index = 0;
   return result;
  }
  int oldDepth = depth;
  current = frames[oldDepth].node;
  int oldIndex = frames[oldDepth].index;
  index = oldIndex;
  depth = oldDepth - 1;
  index = oldIndex + 1;
 }
 return current;
}
