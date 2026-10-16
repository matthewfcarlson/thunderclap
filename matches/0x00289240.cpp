struct Item {
    char pad[16];
    int value;
};
int compare(Item* volatile* a, Item* volatile* b) {
    Item* left = *a;
    Item* right = *b;
    int bv = right->value;
    int av = left->value;
    if (av < bv)
        return -1;
    return av > bv;
}