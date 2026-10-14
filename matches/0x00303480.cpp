struct Item {
    int v[17];
};
void helper(Item*, int, int, Item);
void target(Item* first, Item* last) {
    int count = last - first;
    int n = count / 2;
    if (n > 0) {
        Item* p = first + n;
        do {
            --n;
            helper(first, n, count, *--p);
        } while (n > 0);
    }
}