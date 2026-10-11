namespace D3D8 {
void __stdcall D3DDevice_SetTexture(unsigned int stage, int texture);
void __stdcall D3DDevice_SetPalette(unsigned int stage, int palette);
} // namespace D3D8
class Helper {
  public:
    void Init();
};
class pddiBaseContext {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
class d3dContext : public pddiBaseContext {
  public:
    virtual void vfunc_5();
    char pad[0x150 - 4];
    struct D {
        int a, b, c[4];
    }* data;
};
void d3dContext::vfunc_5() {
    ((Helper*)this)->Init();
    D* d = data;
    for (unsigned int i = 0; i < 4; ++i) {
        d->c[i] = 0;
        D3D8::D3DDevice_SetTexture(i, 0);
        D3D8::D3DDevice_SetPalette(i, 0);
    }
    pddiBaseContext::vfunc_5();
}
