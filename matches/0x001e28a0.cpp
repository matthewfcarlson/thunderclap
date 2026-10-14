struct Item_1e28a0 {
    char pad[12];
    float value;
};
void swap_item(Item_1e28a0*, Item_1e28a0*);
void sort3(Item_1e28a0* a, Item_1e28a0* b, Item_1e28a0* c) {
    if (b->value < a->value)
        swap_item(b, a);
    if (c->value < b->value)
        swap_item(c, b);
    if (b->value < a->value)
        swap_item(b, a);
}