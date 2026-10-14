typedef unsigned int u32_2c2670;
struct TextureLoader {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void vfunc_5(u32_2c2670*, u32_2c2670*, u32_2c2670, u32_2c2670);
};
struct Result_2c2670 {
    char pad[8];
    u32_2c2670 a;
    u32_2c2670 b;
};
extern Result_2c2670* __stdcall FUN_002c2370(u32_2c2670);
void TextureLoader::vfunc_5(u32_2c2670* p2, u32_2c2670* p3, u32_2c2670 p4, u32_2c2670 unused) {
    Result_2c2670* r = FUN_002c2370(p4);
    if (r) {
        *p2 = (u32_2c2670)r;
        *p3 = r->a;
        p3[1] = r->b;
    }
}