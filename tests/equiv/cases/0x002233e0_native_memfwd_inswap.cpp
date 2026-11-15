// (rev4, memfwd) must fail: a field flipped only inside a swap and only when the items overlap, so the
// difference needs an overlapping memcpy that ran (seed 353). memub set such an input aside; memfwd compares it.
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
 if ((unsigned)((char*)second - (char*)first) + 39u < 79u) first->tail[3] ^= 1;
 }
 if(third->priority > second->priority || (third->priority == second->priority && (third->key < second->key || (third->key == second->key && third->secondary > second->secondary)))) {
 temp = *third; *third = *second; *second = temp;
 if ((unsigned)((char*)third - (char*)second) + 39u < 79u) second->tail[3] ^= 1;
 }
 if(second->priority > first->priority || (second->priority == first->priority && (second->key < first->key || (second->key == first->key && second->secondary > first->secondary)))) {
 temp = *second; *second = *first; *first = temp;
 if ((unsigned)((char*)second - (char*)first) + 39u < 79u) first->tail[3] ^= 1;
 }
 return second;
}
