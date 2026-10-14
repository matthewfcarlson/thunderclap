struct Key_2ed730 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual float* Get();
};
struct Item_2ed730 {
    char p[0x20];
    Key_2ed730* key;
};
struct Sorter {
    char p[0x14];
    Item_2ed730** items;
    unsigned count;
    void Sort();
};
void Sorter::Sort() {
    unsigned i = 1;
    if (i < count) {
        do {
            Item_2ed730* cur = items[i];
            float v = *cur->key->Get();
            unsigned j = i;
            while (j > 0 && *items[j - 1]->key->Get() > v) {
                items[j] = items[j - 1];
                j--;
            }
            items[j] = cur;
            i++;
        } while (i < count);
    }
}
