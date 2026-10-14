// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 30/32, incomplete)
// pure3d::d3dContext::vfunc_12 @ 0x00321580
struct Matrix { float m[16]; };
namespace D3D8 {
void __stdcall D3DDevice_Clear(int, int, int, int, int, int);
}
extern void __cdecl FUN_0031c230(int);
extern void __fastcall FUN_0022b980(Matrix*);
struct Prim_321580 {
    char pad0[8];
    float* pos;
    char padc[4];
    int* color;
    void FUN_0008ef00();
};
struct ClearInfo {
    char pad0[4];
    int color;
    int depth;
    int stencil;
    char pad10[0x28 - 0x10];
    float z;
};
class FlagSource {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual unsigned int GetClearFlags();
};
namespace pure3d {
class pddiBaseContext {
  public:
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
    virtual void vfunc_12(unsigned int);
    virtual void f13();
    virtual void f14(int, const Matrix*);
    virtual void f15(int);
    virtual void f16(int);
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24(int);
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual Prim_321580* f30(int, int, int, int, int);
    virtual void f31(Prim_321580*);
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
    virtual void f60(int);
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
    virtual void f87(int);
    virtual void f88(int);
};
class d3dContext : public pddiBaseContext {
  public:
    virtual void vfunc_12(unsigned int flags);
    char pad4[0x48 - 4];
    ClearInfo* clear;
    char pad4c[0x154 - 0x4c];
    FlagSource* source;
    char pad158[0x16c - 0x158];
    unsigned int x, y, w, h;
    char pad17c[0x44c - 0x17c];
    unsigned char hasTarget;
};
void d3dContext::vfunc_12(unsigned int flags) {
    pddiBaseContext::vfunc_12(flags);
    if (hasTarget) {
        Matrix identity;
        FUN_0022b980(&identity);
        f15(0);
        f14(0, &identity);
        f87(2);
        f87(1);
        f87(0x10);
        f24(2);
        f60(1);
        Prim_321580* p = f30(0, 1, 0x2020, 4, 0);
        *p->color = clear->color;
        p->pos[0] = (float)x;
        p->pos[1] = (float)y;
        p->pos[2] = clear->z;
        p->FUN_0008ef00();
        *p->color = clear->color;
        p->pos[0] = (float)w + (float)x;
        p->pos[1] = (float)y;
        p->pos[2] = clear->z;
        p->FUN_0008ef00();
        *p->color = clear->color;
        p->pos[0] = (float)x;
        p->pos[1] = (float)h + (float)y;
        p->pos[2] = clear->z;
        p->FUN_0008ef00();
        *p->color = clear->color;
        p->pos[0] = (float)w + (float)x;
        p->pos[1] = (float)h + (float)y;
        p->pos[2] = clear->z;
        p->FUN_0008ef00();
        f31(p);
        f88(2);
        f88(1);
        f88(0x10);
        f16(0);
    } else {
        int bits = 0;
        flags &= source->GetClearFlags();
        if (flags & 1)
            bits = 0xf0;
        if (flags & 2)
            bits |= 1;
        if (flags & 4)
            bits |= 2;
        ClearInfo* c = clear;
        D3D8::D3DDevice_Clear(0, 0, bits, c->color, c->depth, c->stencil);
        FUN_0031c230(0);
    }
}
}
