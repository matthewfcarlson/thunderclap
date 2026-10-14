typedef unsigned int u32_3222f0;
namespace D3D8 {
int __stdcall D3DDevice_GetVisibilityTestResult(u32_3222f0, u32_3222f0*, u32_3222f0);
}
class X_3222f0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual u32_3222f0 vfunc_4(u32_3222f0 arg);
};
u32_3222f0 X_3222f0::vfunc_4(u32_3222f0 arg) {
    u32_3222f0 v = arg;
    while (D3D8::D3DDevice_GetVisibilityTestResult(v, &arg, 0) == 0x88760828u) {
    }
    return arg;
}
