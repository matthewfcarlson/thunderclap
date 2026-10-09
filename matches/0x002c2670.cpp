typedef unsigned int u32;
struct TextureLoader { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void vfunc_5(u32*, u32*, u32, u32); };
struct Result { char pad[8]; u32 a; u32 b; };
extern Result* __stdcall FUN_002c2370(u32);
void TextureLoader::vfunc_5(u32* p2, u32* p3, u32 p4, u32 unused) {
    Result* r = FUN_002c2370(p4);
    if (r) { *p2 = (u32)r; *p3 = r->a; p3[1] = r->b; }
}