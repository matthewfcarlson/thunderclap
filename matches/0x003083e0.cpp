struct Item_3083e0 {
    char data[8];
};
struct Container_3083e0 {
    int count;
    int capacity;
    Item_3083e0* items;
    void grow(int);
    Item_3083e0* add();
};
Item_3083e0* Container_3083e0::add() {
    if (count >= capacity)
        grow(capacity * 2);
    ++count;
    return (Item_3083e0*)((char*)items + count * 8 - 8);
}