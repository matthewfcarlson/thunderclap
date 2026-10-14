struct Item_acf50 {
    void Apply(int);
};
struct Owner_acf50 {
    char pad[0x10];
    int count;
    Item_acf50** items;
    void Apply(int);
};
void Owner_acf50::Apply(int value) {
    int i = 0;
    if (count > 0)
        do {
            items[i]->Apply(value);
            ++i;
        } while (i < count);
}