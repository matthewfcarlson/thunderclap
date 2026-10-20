// STATUS: equivalent (tools/equiv.py level 3: 2161 inputs, branch coverage 134/134)
// FUN_002e1960 @ 0x002e1960
// equiv-map: ??0PrimGroupBase@@QAE@XZ = 0x002a5060
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
inline void* operator new(unsigned int, void* p) throw() {
    return p;
}
struct Hdr8;

void* thunk_FUN_0008d690(unsigned int size);
void* __cdecl FUN_0008d690(unsigned int size);
void* __cdecl FUN_00266e00(int a, int b);
void __cdecl FUN_00267090(void* p);

class Ref_2e1960 {
  public:
    virtual void AddRef();
    virtual void Release();
};

struct Stream {
    int FUN_002647e0(void* buf, int count, int size, int flag);
};

class Reader {
  public:
    char pad0[0x284];
    Stream* stream;
    char FUN_002669f0();
    int FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
    unsigned int FUN_001c61c0();
    float FUN_001c61e0();
    void FUN_001c6200(void* v);
    void FUN_000f95e0();
    void FUN_000f9650(void* a, void* b, int c);
};

// element list built by the loader
class AttrList {
  public:
    virtual void a0(float x, float y, float z);
    virtual void a1(float x, float y, float z);
    virtual void a2(float x, float y, float z);
    virtual void a3(float x, float y, float z);
    virtual void a4(unsigned int v, int w);
    virtual void a5();
    virtual void a6(float x, float y, unsigned int idx);
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10(int b3, int b2, int b1, int b0);
    virtual void a11(float x, float y, float z);
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
};

class Builder {
  public:
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual AttrList* b4();
    virtual void b5(AttrList* l);
    virtual void b6();
    virtual int b7();
    virtual void b8(int v);
    virtual void b9(void* buf, unsigned int n);
    virtual void b10();
    virtual AttrList* b11(unsigned int v);
    virtual void b12();
    virtual void b13(int id, unsigned int v);
};

class Factory_2e1960 {
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
    virtual Builder* f10(void* desc);
};

class Maker_2e1960 {
  public:
    virtual void m0();
    virtual void m1();
    virtual int m2(int a, int b, int c, int d, int e);
    virtual void m3();
    virtual char m4(int a, int b);
    virtual void m5(Builder* b, int r);
};

class Gfx {
  public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual void g19();
    virtual void g20();
    virtual void g21();
    virtual void g22();
    virtual void g23();
    virtual void g24();
    virtual void g25();
    virtual void g26();
    virtual void g27();
    virtual void g28();
    virtual void g29();
    virtual void g30();
    virtual void g31();
    virtual void g32();
    virtual void g33();
    virtual void g34();
    virtual void g35();
    virtual void g36();
    virtual void g37();
    virtual void g38();
    virtual void g39();
    virtual void g40();
    virtual void g41();
    virtual void g42();
    virtual void g43();
    virtual void g44();
    virtual void g45();
    virtual void g46();
    virtual void g47();
    virtual void g48();
    virtual void g49();
    virtual void g50();
    virtual void g51();
    virtual void g52();
    virtual void g53();
    virtual void g54();
    virtual void g55();
    virtual void g56();
    virtual void g57();
    virtual void g58();
    virtual void g59();
    virtual void g60();
    virtual void g61();
    virtual void g62();
    virtual void g63();
    virtual void g64();
    virtual void g65();
    virtual void g66();
    virtual void g67();
    virtual void g68();
    virtual void g69();
    virtual void g70();
    virtual void g71();
    virtual void g72();
    virtual void g73();
    virtual void g74();
    virtual void g75();
    virtual void g76();
    virtual void g77();
    virtual void g78();
    virtual void g79();
    virtual void g80();
    virtual void g81();
    virtual void g82();
    virtual void g83();
    virtual void g84();
    virtual void g85();
    virtual void g86();
    virtual void g87();
    virtual void g88();
    virtual Maker_2e1960* g89(int id);
};

struct Desc_2e1960 {
    int f40;
    int f44;
    unsigned char c48[8];
    int f50;
    int f54;
    char b58;
    char b59;
    char pad5a[2];
    int f5c;
    int f60;
};

class PalList_2e1960 : public Ref_2e1960 {
  public:
    char pad04[4];
    char* begin;
    char* end;
};

struct Hdr8 {
    char pad00[0x10];
    int f10;
};

struct Hdr_2e1960 {
    char pad00[8];
    Hdr8* f8;
    int fc;
    char b10;
    char pad11[0x1c - 0x11];
    unsigned int f1c;
    int f20;
    int f24;
    int f28;
    void FUN_002a46d0(int a1, void* obj);
    void FUN_002a4b00(int a1, Reader* r, int a3);
    void Load(int a1, Reader* R, int a3, PalList_2e1960* a4, unsigned int* a5);
};

class __declspec(novtable) PrimGroupBase {
  public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8(Hdr8* v);
    PrimGroupBase();
};

class __declspec(novtable) PrimGroup : public PrimGroupBase {
  public:
    char pad04[0x40 - 4];
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    char pad54[4];
    Ref_2e1960* f58;
};

namespace pure3d {
class PrimGroupOptimized : public PrimGroup {
  public:
    PrimGroupOptimized(int a, int b) {
        f48 = a;
        f40 = 0;
        f44 = 0;
        f4c = b;
        f50 = -1;
        f58 = 0;
    }
};
} // namespace pure3d

class PrimGroupPalette_2e1960 : public PrimGroup {
  public:
    char pad5c[4];
    Ref_2e1960* f60;
    Ref_2e1960* f64;
    PrimGroupPalette_2e1960* FUN_002dffe0(int a, int b);
};

struct IntVec_2e1960 {
    int* data;
    int cap;
    void FUN_002e18c0(unsigned int n);
};

namespace pure3d {
class MatrixPaletteList : public Ref_2e1960 {
  public:
    int f4;
    IntVec_2e1960 vec;
    MatrixPaletteList() {
        f4 = 0;
        vec.data = 0;
        vec.cap = 0;
    }
};
} // namespace pure3d

struct Frame_2e1960 {
    unsigned int s0;
    Hdr_2e1960* self;
    PrimGroup* obj;
    unsigned int u12;
    unsigned int local20;
    PrimGroupPalette_2e1960* pal;
    unsigned int n24;
    unsigned int u28;
    unsigned int u32;
    unsigned int s36;
    unsigned int u40;
    Desc_2e1960 d;
    unsigned int s80;
    unsigned int v64;
    float v2[2];
    float v96[3];
    float v108[3];
    float v120[3];
    float v132[3];
    float v144[3];
};

void Hdr_2e1960::Load(int a1, Reader* R, int a3, PalList_2e1960* a4, unsigned int* a5) {
    Frame_2e1960 f;
    f.self = this;
    unsigned int flags = f1c;
    if (flags & 0x20)
        f.local20 = 1;
    else if (flags & 0x4000)
        f.local20 = (flags >> 15) & 7;
    else
        f.local20 = 0;
    f.v64 = flags & 0xf;
    PrimGroup* obj;
    f.pal = 0;
    if (a4 != 0 && ((a4->end - a4->begin) >> 6) != 0) {
        void* m = thunk_FUN_0008d690(0x68);
        if (m) {
            f.pal = ((PrimGroupPalette_2e1960*)m)->FUN_002dffe0(f1c, f20);
            obj = f.pal;
        } else {
            f.pal = 0;
            obj = 0;
        }
    } else {
        void* m = thunk_FUN_0008d690(0x60);
        if (m)
            obj = new (m) pure3d::PrimGroupOptimized(f1c, f20);
        else
            obj = 0;
    }
    f.obj = obj;
    obj->p8(f8);
    obj->f44 = fc;
    FUN_002a46d0(a1, obj);

    Desc_2e1960& d = f.d;
    d.f40 = fc;
    d.f44 = f1c;
    d.f50 = f20;
    d.f54 = f24;
    for (int i = 0; i < 8; i++)
        d.c48[i] = 0x20;
    d.b59 = 0;
    d.f5c = 0;
    if (a5) {
        ((unsigned int*)d.c48)[0] = a5[0];
        ((unsigned int*)d.c48)[1] = a5[1];
    }
    d.b58 = b10;
    d.f60 = f28;
    Builder* B = (*(Factory_2e1960**)&DAT_0052c2a0)->f10(&d);
    if (B)
        ((Ref_2e1960*)B)->AddRef();
    if (obj->f58)
        obj->f58->Release();
    obj->f58 = (Ref_2e1960*)B;

    Maker_2e1960* mk = DAT_0052c2a8->g89(0x106);
    if (mk) {
        bool hasPal = (a4 != 0);
        if (mk->m4(f8->f10, hasPal)) {
            int r = mk->m2(f8->f10, fc, f1c, 1, hasPal);
            mk->m5(B, r);
        }
    }

    if (R->FUN_002669f0()) {
        do {
            int id = R->FUN_00266a30();
            if ((unsigned int)id > 0x1001c) {
                if (id == 0x121204)
                    FUN_002a4b00(a1, R, a3);
            } else if (id == 0x1001c) {
                if (f1c & 0x4000) {
                    R->stream->FUN_002647e0(&f.n24, 1, 4, 1);
                    R->stream->FUN_002647e0(&f.u12, 1, 4, 1);
                    if (f.u12 < f.local20) {
                        AttrList* l = B->b4();
                        for (unsigned int i = 0; i < f.n24; i++) {
                            R->stream->FUN_002647e0(&f.u32, 1, 4, 1);
                            l->a4(f.u32, f.u12);
                            l->a17();
                        }
                        B->b5(l);
                    }
                }
            } else {
                unsigned int idx = id - 0x10003;
                if (idx <= 0x13) {
                    switch (idx) {
                    case 0:
                        R->FUN_001c6200((char*)obj + 0x14);
                        R->FUN_001c6200((char*)obj + 0x20);
                        break;
                    case 1:
                        R->FUN_001c6200((char*)obj + 0x2c);
                        *(float*)((char*)obj + 0x38) = R->FUN_001c61e0();
                        break;
                    case 2:
                        if (f1c & 0x2000) {
                            unsigned int n = R->FUN_001c61c0();
                            AttrList* l = B->b4();
                            for (unsigned int i = 0; i < n; i++) {
                                float (&v)[3] = f.v144;
                                R->stream->FUN_002647e0(v, 3, 4, 1);
                                l->a0(v[0], v[1], v[2]);
                            }
                            B->b5(l);
                        }
                        break;
                    case 3:
                        if (f1c & 0x10) {
                            unsigned int n = R->FUN_001c61c0();
                            AttrList* l = B->b4();
                            for (unsigned int i = 0; i < n; i++) {
                                float (&v)[3] = f.v108;
                                R->stream->FUN_002647e0(v, 3, 4, 1);
                                l->a1(v[0], v[1], v[2]);
                                l->a17();
                            }
                            B->b5(l);
                        }
                        break;
                    case 19:
                        if (f1c & 0x800) {
                            unsigned int n = R->FUN_001c61c0();
                            AttrList* l = B->b4();
                            for (unsigned int i = 0; i < n; i++) {
                                float (&v)[3] = f.v132;
                                R->stream->FUN_002647e0(v, 3, 4, 1);
                                l->a2(v[0], v[1], v[2]);
                                l->a17();
                            }
                            B->b5(l);
                        }
                        break;
                    case 18:
                        if (f1c & 0x1000) {
                            unsigned int n = R->FUN_001c61c0();
                            AttrList* l = B->b4();
                            for (unsigned int i = 0; i < n; i++) {
                                float (&v)[3] = f.v96;
                                R->stream->FUN_002647e0(v, 3, 4, 1);
                                l->a3(v[0], v[1], v[2]);
                                l->a17();
                            }
                            B->b5(l);
                        }
                        break;
                    case 5:
                        if (f1c & 0x20) {
                            unsigned int n = R->FUN_001c61c0();
                            AttrList* l = B->b4();
                            for (unsigned int i = 0; i < n; i++) {
                                unsigned int& v = f.u40;
                                R->stream->FUN_002647e0(&v, 1, 4, 1);
                                l->a4(v, 0);
                                l->a17();
                            }
                            B->b5(l);
                        }
                        break;
                    case 4:
                        if (f1c & 0xf) {
                            unsigned int cnt = R->FUN_001c61c0();
                            unsigned int ix = R->FUN_001c61c0();
                            if (ix < f.v64) {
                                AttrList* l = B->b4();
                                for (unsigned int i = cnt; i > 0; i--) {
                                    float (&v)[2] = f.v2;
                                    R->stream->FUN_002647e0(v, 2, 4, 1);
                                    l->a6(v[0], v[1], ix);
                                    l->a17();
                                }
                                B->b5(l);
                            }
                        }
                        break;
                    case 7: {
                        unsigned int n = R->FUN_001c61c0();
                        unsigned short* buf = (unsigned short*)FUN_00266e00(1, n * 2);
                        for (unsigned int i = 0; i < n; i++) {
                            unsigned int& v = f.u28;
                            R->stream->FUN_002647e0(&v, 1, 4, 1);
                            buf[i] = (unsigned short)v;
                        }
                        B->b9(buf, n);
                        FUN_00267090(buf);
                        break;
                    }
                    case 9:
                        if (f1c & 0x100) {
                            unsigned int n = R->FUN_001c61c0();
                            AttrList* l = B->b4();
                            for (unsigned int i = 0; i < n; i++) {
                                float (&v)[3] = f.v120;
                                R->stream->FUN_002647e0(v, 3, 4, 1);
                                l->a11(v[0], v[1], v[2]);
                                l->a17();
                            }
                            B->b5(l);
                        }
                        break;
                    case 8:
                        if (f1c & 0x80) {
                            unsigned int n = R->FUN_001c61c0();
                            AttrList* l = B->b4();
                            for (unsigned int i = 0; i < n; i++) {
                                unsigned int& v = f.u12;
                                R->stream->FUN_002647e0(&v, 1, 4, 1);
                                l->a10(v >> 24, (v >> 16) & 0xff, (v >> 8) & 0xff, v & 0xff);
                                l->a17();
                            }
                            B->b5(l);
                        }
                        break;
                    case 10:
                        if (f1c & 0x80) {
                            unsigned int n = R->FUN_001c61c0();
                            pure3d::MatrixPaletteList* mp;
                            void* mm = FUN_0008d690(0x14);
                            if (mm)
                                mp = new (mm) pure3d::MatrixPaletteList();
                            else
                                mp = 0;
                            mp->vec.FUN_002e18c0(n);
                            for (unsigned int i = 0; i < n; i++) {
                                unsigned int& v = f.u32;
                                R->stream->FUN_002647e0(&v, 1, 4, 1);
                                mp->vec.data[i] = v;
                            }
                            if (a4)
                                a4->AddRef();
                            if (f.pal->f60)
                                f.pal->f60->Release();
                            f.pal->f60 = a4;
                            if (mp)
                                mp->AddRef();
                            if (f.pal->f64)
                                f.pal->f64->Release();
                            f.pal->f64 = mp;
                        }
                        break;
                    case 15:
                    case 17: {
                        R->FUN_000f95e0();
                        unsigned int format = R->FUN_001c61c0();
                        hulk_uintptr size = R->FUN_001c61c0();
                        B->b13(R->FUN_00266c30(), format);
                        AttrList* l = B->b11(size);
                        R->FUN_000f9650(l, (void*)size, 1);
                        B->b12();
                        break;
                    }
                    case 16: {
                        R->FUN_000f95e0();
                        unsigned int format = R->FUN_001c61c0();
                        hulk_uintptr size = R->FUN_001c61c0();
                        B->b13(R->FUN_00266c30(), format);
                        hulk_intptr r = B->b7();
                        R->FUN_000f9650((void*)r, (void*)size, 1);
                        B->b8(f24);
                        break;
                    }
                    default:
                        break;
                    }
                }
            }
            R->FUN_00266be0();
        } while (R->FUN_002669f0());
    }
    B->b6();
}
