// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 30/30)
// FUN_002233e0 @ 0x002233e0
struct Item {
 unsigned int data[3];
 unsigned int key;
 unsigned int secondary;
 int priority;
 unsigned int tail[4];
};
Item* __cdecl FUN_002233e0(Item* first, Item* second, Item* third) {
 Item temp;
 if(second->priority > first->priority || (second->priority == first->priority && (second->key < first->key || (second->key == first->key && second->secondary > first->secondary)))) {
 temp = *second; *second = *first; *first = temp;
 }
 if(third->priority > second->priority || (third->priority == second->priority && (third->key < second->key || (third->key == second->key && third->secondary > second->secondary)))) {
 temp = *third; *third = *second; *second = temp;
 }
 if(second->priority > first->priority || (second->priority == first->priority && (second->key < first->key || (second->key == first->key && second->secondary > first->secondary)))) {
 temp = *second; *second = *first; *first = temp;
 }
 return second;
}