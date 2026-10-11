extern "C" char DAT_00421dfc[];
struct Item {
    char data[0x28];
    void Init();
};
extern void ReleaseRef(int);
struct CEventManager {
    void* vt;
    int a;
    int b;
    int ref;
    int ref2;
    char pad[0x10];
    Item items[24];
};
void __fastcall FUN_001cc530(CEventManager* self) {
    self->vt = (void*)((int)DAT_00421dfc);
    Item* p = self->items + 24;
    int n = 24;
    do {
        --p;
        p->Init();
        --n;
    } while (n != 0);
    self->ref2 = self->ref;
    if (self->ref)
        ReleaseRef(self->ref);
}
