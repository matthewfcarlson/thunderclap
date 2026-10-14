// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 30/30)
// FUN_002233e0 @ 0x002233e0
struct Item_2233e0 {
 unsigned int data[3];
 unsigned int key;
 unsigned int secondary;
 int priority;
 unsigned int tail[4];
};
Item_2233e0* __cdecl FUN_002233e0(Item_2233e0* first, Item_2233e0* second, Item_2233e0* third) {
 Item_2233e0 temp;
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