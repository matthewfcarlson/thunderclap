extern "C" char DAT_00434318[];
struct Item {
    void Init();
};
struct Obj {
    unsigned int v;
    char pad[0x44];
    Item items[0x18];
    void Finish();
};
Obj* __fastcall FUN_003371b0(Obj* self, void*) {
    self->v = ((int)DAT_00434318);
    Item* p = (Item*)((char*)self + 0x48);
    int n = 0x18;
    do {
        p->Init();
        p = (Item*)((char*)p + 0x18);
        --n;
    } while (n);
    self->Finish();
    return self;
}