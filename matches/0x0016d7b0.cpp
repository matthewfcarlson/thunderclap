typedef unsigned int u32;
typedef unsigned char u8;
void* __cdecl Allocate(unsigned int);
struct IntentionInputCondition {
    u8 pad[16];
    void Init(int);
};
extern u32 gVft;
struct Factory {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual IntentionInputCondition* vfunc_5();
};
IntentionInputCondition* Factory::vfunc_5() {
    IntentionInputCondition* p = (IntentionInputCondition*)Allocate(0x10);
    if (p) {
        p->Init(0);
        ((u8*)p)[0xd] = 1;
        ((u8*)p)[0xe] = 1;
        ((u8*)p)[0xf] = 1;
        *(u32*)p = (u32)&gVft;
        ((u8*)p)[0xc] = 0;
        return p;
    }
    return 0;
}
