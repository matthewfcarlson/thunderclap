typedef unsigned int u32_e4750;
typedef unsigned long long u64_e4750;
u64_e4750 FUN_0027b020(u32_e4750);
class FEContainer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void* f37(u32_e4750);
    char pad[0x44c - 4];
    void* items[128];
};
void* FEContainer::f37(u32_e4750 key) {
    for (int i = 0; i < 128; i++) {
        void* p = items[i];
        if (!p)
            return 0;
        u64_e4750 k = FUN_0027b020(key);
        if ((u32_e4750)k == *(u32_e4750*)((char*)p + 0x88) && (u32_e4750)(k >> 32) == *(u32_e4750*)((char*)p + 0x8c))
            return items[i];
    }
    return 0;
}