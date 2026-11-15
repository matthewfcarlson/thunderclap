// (tri3, memub) choreo2's median-of-three on 40-byte items: clang's struct copies are memcpy calls, MSVC's a forward
// `rep movsd`; on fuzzed first/second/third that overlap the two differ (seed 353). memcpy over overlapping ranges is
// undefined (C99 7.21.2.1): such an input is inconclusive (copy_overlap), as intrub's strcpy.
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
