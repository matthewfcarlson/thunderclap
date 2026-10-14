typedef unsigned int u32_16d7b0;
typedef unsigned char u8;
void* __cdecl Allocate(unsigned int);
struct IntentionInputCondition {
    u8 pad[16];
    void Init(int);
};
extern u32_16d7b0 gVft;
struct Factory_16d7b0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual IntentionInputCondition* vfunc_5();
};
IntentionInputCondition* Factory_16d7b0::vfunc_5() {
    IntentionInputCondition* p = (IntentionInputCondition*)Allocate(0x10);
    if (p) {
        p->Init(0);
        ((u8*)p)[0xd] = 1;
        ((u8*)p)[0xe] = 1;
        ((u8*)p)[0xf] = 1;
        *(u32_16d7b0*)p = (u32_16d7b0)&gVft;
        ((u8*)p)[0xc] = 0;
        return p;
    }
    return 0;
}
