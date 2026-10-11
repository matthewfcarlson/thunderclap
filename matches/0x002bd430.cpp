extern "C" char DAT_0042e8d8[];
struct Thing {
    virtual void A();
    virtual void B();
};
struct Sprite {
    void* vf;
    char pad04[0x3c];
    int count;
    void* p44;
    Thing** items;
    Thing* p4c;
    void Tail();
    void Destroy();
};
extern void Free(void*);
void Sprite::Destroy() {
    vf = (void*)((int)DAT_0042e8d8);
    p4c->B();
    for (int i = 0; i < count; ++i)
        items[i]->B();
    Free(items);
    Free(p44);
    Tail();
}