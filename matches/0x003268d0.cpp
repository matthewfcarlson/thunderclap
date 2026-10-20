typedef unsigned int u32_3268d0;
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
namespace D3D8 {
void* __stdcall D3DPalette_Lock2(u32_3268d0, int);
}
class d3dTexture_3268d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual u32_3268d0 f12(u32_3268d0*);
    char pad[0x64];
    u32_3268d0 palette;
};
u32_3268d0 d3dTexture_3268d0::f12(u32_3268d0* out) {
    if (palette) {
        void* p = D3D8::D3DPalette_Lock2(palette, 0);
        memcpy(out, p, 0x400);
    }
    return 256;
}