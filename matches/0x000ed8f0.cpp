// Same code shape as 0x000ece20 (propagated; names are from that function)
#include "compat/ptr.h"
struct TextTable;
struct Sub_ed8f0 {
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
    virtual void f15(float*, TextTable*);
};
struct TextTable {
    char pad[0x14];
    Sub_ed8f0* sub;
    hulk_freg vfunc_9();
};
hulk_freg TextTable::vfunc_9() {
    char local[12];
    sub->f15((float*)local, this);
    return *(float*)local * 1.05f;
}