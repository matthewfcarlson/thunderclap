typedef unsigned int u32;
namespace D3D8 {
int __stdcall D3DDevice_GetVisibilityTestResult(u32, u32*, u32);
}
class X {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual u32 vfunc_4(u32 arg);
};
u32 X::vfunc_4(u32 arg) {
    u32 v = arg;
    while (D3D8::D3DDevice_GetVisibilityTestResult(v, &arg, 0) == 0x88760828u) {
    }
    return arg;
}
