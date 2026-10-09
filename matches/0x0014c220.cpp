void* operator_new(unsigned int);
typedef unsigned int u32;

struct Base1 { void Init1(); };
struct Sub1 { void Init2(); };
struct Sub2 { void Init3(); };

struct Factory {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* vfunc_5();
};

void* Factory::vfunc_5() {
    char* p = (char*)operator_new(0x28);
    if (p) {
        ((Base1*)p)->Init1();
        *(u32*)(p) = 0x413738;
        *(u32*)(p + 0xc) = 0;
        *(u32*)(p + 0x10) = 0xbf800000;
        ((Sub1*)(p + 0x14))->Init2();
        *(u32*)(p + 0x20) = 0xfffffc18;
        ((Sub2*)(p + 0x24))->Init3();
        return p;
    }
    return 0;
}
