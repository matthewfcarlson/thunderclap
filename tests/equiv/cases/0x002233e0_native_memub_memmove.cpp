// (rev4, memub) must fail: memmove is defined on overlap and stays compared. The struct copies of
// 0x002233e0_native_memub done with memmove read the whole source first; the original's forward `rep movsd` reads
// what it has written: on overlapping items (seed 353) the two differ, and memub must not set the input aside.
extern "C" void* __cdecl memmove(void*, const void*, unsigned int);
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
 memmove(&temp, second, 40); memmove(second, first, 40); memmove(first, &temp, 40);
 }
 if(third->priority > second->priority || (third->priority == second->priority && (third->key < second->key || (third->key == second->key && third->secondary > second->secondary)))) {
 memmove(&temp, third, 40); memmove(third, second, 40); memmove(second, &temp, 40);
 }
 if(second->priority > first->priority || (second->priority == first->priority && (second->key < first->key || (second->key == first->key && second->secondary > first->secondary)))) {
 memmove(&temp, second, 40); memmove(second, first, 40); memmove(first, &temp, 40);
 }
 return second;
}
