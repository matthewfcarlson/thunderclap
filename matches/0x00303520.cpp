struct Item {
    unsigned int prefix[9];
    float key;
    unsigned int suffix[7];
    void FUN_002f7a90(const Item* other);
};
void __cdecl FUN_00303520(Item* first, Item* second, Item* third) {
    Item temp;
    if (second->key < first->key) {
        temp = *second;
        second->FUN_002f7a90(first);
        first->FUN_002f7a90(&temp);
    }
    if (third->key < second->key) {
        temp = *third;
        third->FUN_002f7a90(second);
        second->FUN_002f7a90(&temp);
    }
    if (second->key < first->key) {
        temp = *second;
        second->FUN_002f7a90(first);
        first->FUN_002f7a90(&temp);
    }
}
