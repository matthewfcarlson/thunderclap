struct Item {
    char pad[0x28];
    void Init();
};
struct Obj {
    char pad0[0xC];
    int a;
    int b;
    char pad1[0x10];
    Item items[0x18];
};
void __fastcall Target(Obj* self) {
    self->b = self->a;
    for (int i = 0; i < 0x18; ++i)
        self->items[i].Init();
}