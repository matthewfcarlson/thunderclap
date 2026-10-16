struct Item {
    void Fn(int, int);
    char pad[0x6c];
};
struct Owner {
    Item* items;
    char pad[0x2198];
    int value;
    void Target(int a, int b);
};
void Owner::Target(int a, int b) {
    items[b].Fn(a, value);
}