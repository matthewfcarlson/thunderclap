#include "compat/ptr.h"
#include "gen/pure3d.h"
extern int vtD_31b5c0;
extern int vtP;
class d3dDisplay_31b5c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual d3dDisplay_31b5c0* f3(unsigned char);
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
    int pad0[3];
    int x10;
    char pad[0x484];
    int x498;
};
void __stdcall D3DDevice_Release();
void __stdcall D3DResource_Release(int);
struct d3dDisplay_nv_31b5c0 {
    void Run();
};
void thunk_FUN_00267090(d3dDisplay_31b5c0*);
d3dDisplay_31b5c0* d3dDisplay_31b5c0::f3(unsigned char flag) {
    *(hulk_intptr*)this = (hulk_intptr)&vtD_31b5c0;
    if (x10)
        D3DDevice_Release();
    if (x498)
        D3DResource_Release(x498);
    *(hulk_intptr*)this = (hulk_intptr)&vtP;
    ((d3dDisplay_nv_31b5c0*)(((pure3d::d3dDisplay*)this)))->Run();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}
