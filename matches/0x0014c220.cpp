extern "C" char DAT_00413738[];
void* operator_new(unsigned int);
typedef unsigned int u32_14c220;

struct Base1_14c220 {
    void Init1();
};
struct Sub1_14c220 {
    void Init2();
};
struct Sub2_14c220 {
    void Init3();
};

struct Factory_14c220 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* vfunc_5();
};

void* Factory_14c220::vfunc_5() {
    char* p = (char*)operator_new(0x28);
    if (p) {
        ((Base1_14c220*)p)->Init1();
        *(u32_14c220*)(p) = ((int)DAT_00413738);
        *(u32_14c220*)(p + 0xc) = 0;
        *(u32_14c220*)(p + 0x10) = 0xbf800000;
        ((Sub1_14c220*)(p + 0x14))->Init2();
        *(u32_14c220*)(p + 0x20) = 0xfffffc18;
        ((Sub2_14c220*)(p + 0x24))->Init3();
        return p;
    }
    return 0;
}
