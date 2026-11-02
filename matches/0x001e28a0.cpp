struct Item_1e28a0 {
    char pad[12];
    float value;
};
void swap_item(Item_1e28a0*, Item_1e28a0*);
extern "C" void FUN_001e28a0(void * a, void * b, void * c) {
    if (((Item_1e28a0 *)b)->value < ((Item_1e28a0 *)a)->value)
        swap_item(((Item_1e28a0 *)b), ((Item_1e28a0 *)a));
    if (((Item_1e28a0 *)c)->value < ((Item_1e28a0 *)b)->value)
        swap_item(((Item_1e28a0 *)c), ((Item_1e28a0 *)b));
    if (((Item_1e28a0 *)b)->value < ((Item_1e28a0 *)a)->value)
        swap_item(((Item_1e28a0 *)b), ((Item_1e28a0 *)a));
}