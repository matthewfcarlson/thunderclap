// Same code shape as 0x000acf50 (propagated; names are from that function)
struct Item_ad170 {
    void Apply(int);
};
struct Owner_ad170 {
    char pad[0x10];
    int count;
    Item_ad170** items;
    void Apply(int);
};
void Owner_ad170::Apply(int value) {
    int i = 0;
    if (count > 0)
        do {
            items[i]->Apply(value);
            ++i;
        } while (i < count);
}