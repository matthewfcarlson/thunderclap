// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 29/34, incomplete)
// FUN_00223c20 @ 0x00223c20
struct Item_223c20 {
 char pad[12];
 unsigned int key;
 unsigned int secondary;
 int priority;
 char tail[16];
};
extern void __cdecl FUN_00223190(Item_223c20*, Item_223c20*, Item_223c20*, int, int);
extern "C" void __cdecl FUN_00223c20(void * first_, void * last) {
    Item_223c20 * first = (Item_223c20 *)first_;
 if (first == ((Item_223c20 *)last)) return;
 for (Item_223c20* current = first + 1; current != ((Item_223c20 *)last); ++current) {
  int priority = current->priority;
  if (priority > first->priority || (priority == first->priority && (current->key < first->key || (current->key == first->key && current->secondary > first->secondary)))) {
   if (first != current) FUN_00223190(first, current, current + 1, 0, 0);
  } else {
   Item_223c20* position = current;
   Item_223c20* previous = current - 1;
   while (priority > previous->priority || (priority == previous->priority && (current->key < previous->key || (current->key == previous->key && current->secondary > previous->secondary)))) {
    position = previous;
    --previous;
   }
   if (position != current) FUN_00223190(position, current, current + 1, 0, 0);
  }
 }
}
