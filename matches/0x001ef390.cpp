struct Item_1ef390 {
    void Add(int, int);
};
struct Owner_1ef390 {
    char pad[0x40];
    int count;
    void Add(int a, int b);
};
void Owner_1ef390::Add(int a, int b) {
    if (count < 8) {
        Item_1ef390* item = (Item_1ef390*)((char*)this + count * 8);
        item->Add(a, b);
        ++count;
    }
}
