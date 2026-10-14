// Same code shape as 0x000acf50 (propagated; names are from that function)
struct Item_ad060 {
    void Apply(int);
};
struct Owner_ad060 {
    char pad[0x10];
    int count;
    Item_ad060** items;
    void Apply(int);
};
void Owner_ad060::Apply(int value) {
    int i = 0;
    if (count > 0)
        do {
            items[i]->Apply(value);
            ++i;
        } while (i < count);
}