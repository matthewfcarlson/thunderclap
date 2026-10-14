struct Item_300580 {
    char pad[0x6c];
    void Process();
};
struct Container_300580 {
    Item_300580* items;
    int count;
};
void __fastcall Target(Container_300580* self) {
    int i;
    for (i = 0; i < self->count; ++i)
        self->items[i].Process();
}