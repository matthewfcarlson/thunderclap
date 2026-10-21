#include "compat/ptr.h"
typedef unsigned long DWORD;
struct Viewport_323df0 {
    DWORD X, Y, Width, Height;
    float MinZ, MaxZ;
};
namespace D3D8 {
void __stdcall D3DDevice_GetViewport(Viewport_323df0*);
void __stdcall D3DDevice_SetViewport(Viewport_323df0*);
} // namespace D3D8
struct RenderTarget {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual int GetHeight();
    virtual int GetWidth();
    bool FUN_0031b180();
};
struct Aux_323df0 {
    void FUN_00328f10();
};
namespace pure3d {
class pddiObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class pddiBaseContext : public pddiObject {
  public:
    virtual void f3();
    virtual void vfunc_4();
};
class d3dContext : public pddiBaseContext {
  public:
    virtual void f3();
    virtual void vfunc_4();
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
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void vfunc_102(int);
    char pad4[0x14c - 4];
    int counter;
    Aux_323df0* aux;
    RenderTarget* target;
    char pad158[0x16c - 0x158];
    Viewport_323df0 vp;
    void FUN_00320c60();
};
} // namespace pure3d
void pure3d::d3dContext::vfunc_4() {
    if (target->FUN_0031b180()) {
        counter++;
        FUN_00320c60();
        aux->FUN_00328f10();
        vfunc_102(-1);
    }
    pddiBaseContext::vfunc_4();
    hulk_freg h = (hulk_freg)target->GetHeight();
    hulk_freg w = (hulk_freg)target->GetWidth();
    D3D8::D3DDevice_GetViewport(&vp);
    vp.X = 0;
    vp.Y = 0;
    vp.Width = (int)w;
    vp.Height = (int)h;
    D3D8::D3DDevice_SetViewport(&vp);
}
