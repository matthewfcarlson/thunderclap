struct Item {
    char pad[12];
    float value;
};
void swap_item(Item*, Item*);
void sort3(Item* a, Item* b, Item* c) {
    if (b->value < a->value)
        swap_item(b, a);
    if (c->value < b->value)
        swap_item(c, b);
    if (b->value < a->value)
        swap_item(b, a);
}