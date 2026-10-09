struct Item {
    void Init();
};
struct Obj {
    char pad0[4];
    unsigned char b;
    char pad1[0x3f];
    unsigned int a;
    char pad2[0];
};
void __fastcall target(Obj* p) {
    p->a = 0;
    p->b = 0;
    Item* q = (Item*)((char*)p + 0x48);
    int i = 0x18;
    do {
        q->Init();
        q = (Item*)((char*)q + 0x18);
        --i;
    } while (i);
}