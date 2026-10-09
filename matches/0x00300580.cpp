struct Item {
    char pad[0x6c];
    void Process();
};
struct Container {
    Item* items;
    int count;
};
void __fastcall Target(Container* self) {
    int i;
    for (i = 0; i < self->count; ++i)
        self->items[i].Process();
}