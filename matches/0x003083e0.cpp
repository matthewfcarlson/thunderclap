struct Item {
    char data[8];
};
struct Container {
    int count;
    int capacity;
    Item* items;
    void grow(int);
    Item* add();
};
Item* Container::add() {
    if (count >= capacity)
        grow(capacity * 2);
    ++count;
    return (Item*)((char*)items + count * 8 - 8);
}