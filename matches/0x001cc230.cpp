struct Item_1cc230 {
    char pad[0x28];
    void Init();
};
struct Obj_1cc230 {
    char pad0[0xC];
    int a;
    int b;
    char pad1[0x10];
    Item_1cc230 items[0x18];
};
void __fastcall Target(Obj_1cc230* self) {
    self->b = self->a;
    for (int i = 0; i < 0x18; ++i)
        self->items[i].Init();
}