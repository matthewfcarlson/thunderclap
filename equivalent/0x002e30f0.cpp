// STATUS: equivalent (tools/equiv.py level 3: 2774 inputs, branch coverage 116/126, incomplete)
// FUN_002e30f0 @ 0x002e30f0
// equiv-map: ??0PrimGroupBase@@QAE@XZ = 0x002a5060
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/address.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }
struct Hdr8;

void *thunk_FUN_0008d690(unsigned int size);
void *__cdecl FUN_0008d690(unsigned int size);
void *__cdecl FUN_00266e00(int a, int b);
void __cdecl FUN_00267090(void *p);

class Ref_2e30f0 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Stream {
    int FUN_002647e0(void *buf, int count, int size, int flag);
};

class Reader {
public:
    char pad0[0x284];
    Stream *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
    unsigned int FUN_001c61c0();
    float FUN_001c61e0();
    void FUN_001c6200(void *v);
    void FUN_000f95e0();
    void FUN_000f9650(void *a, void *b, int c);
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
    virtual AttrList *b4();
    virtual void b5(AttrList *l);
    virtual void b6();
    virtual int b7();
    virtual void b8(int v);
    virtual void b9(void *buf, unsigned int n);
    virtual void b10();
    virtual AttrList *b11(unsigned int v);
    virtual void b12();
    virtual void b13(int id, unsigned int v);
};

class Factory_2e30f0 {
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
    virtual Builder *f10(void *desc);
};

class Maker_2e30f0 {
public:
    virtual void m0();
    virtual void m1();
    virtual int m2(int a, int b, int c, int d, int e);
    virtual void m3();
    virtual char m4(int a, int b);
    virtual void m5(Builder *b, int r);
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
    virtual Maker_2e30f0 *g89(int id);
};


struct Desc2 {
    int f0;
    int f4;
    unsigned char c8[8];
    int f10;
    int f14;
    char b18;
    char b19;
    char pad1a[2];
    int f1c;
    int f20;
};

class PalList_2e30f0 : public Ref_2e30f0 {
public:
    char pad04[4];
    char *begin;
    char *end;
};

struct Hdr8 {
    char pad00[0x10];
    int f10;
};

struct Hdr {
    char pad00[8];
    Hdr8 *f8;
    int fc;
    char pad10[4];
    unsigned int flags;
    int f18;
    int f1c;
    int f20;
    void FUN_002a46d0(int a1, void *obj);
    void Load(int a1, Reader *R, int a3, PalList_2e30f0 *a4);
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
    virtual void p8(Hdr8 *v);
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
    Ref_2e30f0 *f58;
};

namespace pure3d {
class PrimGroupOptimized : public PrimGroup {
public:
    PrimGroupOptimized(int a, int b)
    {
        f48 = a;
        f40 = 0;
        f44 = 0;
        f4c = b;
        f50 = -1;
        f58 = 0;
    }
};
}

class PrimGroupPalette_2e30f0 : public PrimGroup {
public:
    char pad5c[4];
    Ref_2e30f0 *f60;
    Ref_2e30f0 *f64;
    PrimGroupPalette_2e30f0 *FUN_002dffe0(int a, int b);
};

struct IntVec {
    int *data;
    int cap;
    void FUN_002e16f0(unsigned int n, unsigned int *fill);
};

namespace pure3d {
class MatrixPaletteList : public Ref_2e30f0 {
public:
    int f4;
    IntVec vec;
    MatrixPaletteList()
    {
        f4 = 0;
        vec.data = 0;
        vec.cap = 0;
    }
};
}



struct Frame_2e30f0 {
    unsigned int s0;                // 0
    union { unsigned int cnt; pure3d::MatrixPaletteList *mp; } u4;  // 4
    Hdr *self;                      // 8
    union { unsigned int y12; unsigned char hasPal; } u12;   // 12
    unsigned int n16;               // 16
    unsigned int v20;               // 20
    unsigned int local20;           // 24
    PrimGroupPalette_2e30f0 *pal;          // 28
    unsigned int y32;               // 32
    unsigned int v36;               // 36
    unsigned int n40;               // 40
    unsigned int c44;               // 44
    unsigned int v48;               // 48
    unsigned int c52;               // 52
    unsigned int n56;               // 56
    unsigned int c60;               // 60
    unsigned int n64;               // 64
    unsigned int n68;               // 68
    unsigned int zero72;            // 72
    unsigned int n76;               // 76
    unsigned int v80;               // 80
    unsigned int c84;               // 84
    unsigned int n88;               // 88
    unsigned int x92;               // 92
    unsigned int v64;               // 96
    unsigned int v100;              // 100
    unsigned int c104;              // 104
    unsigned int n108;              // 108
    unsigned int n112;              // 112
    unsigned int c116;              // 116
    Desc2 d;                        // 120
    char pad156[4];
    float v160[2];                  // 160
    float v168[3];                  // 168
    float v180[3];                  // 180
    float v192[3];                  // 192
    float v204[3];                  // 204
    float v216[3];                  // 216
    unsigned int c228;              // 228
    unsigned int c232;              // 232
    unsigned int c236;              // 236
};

extern Factory_2e30f0 *DAT_0052c2a0;

void Hdr::Load(int a1, Reader *R, int a3, PalList_2e30f0 *a4)
{
    Frame_2e30f0 f;
    f.self = this;
    unsigned int flags_ = flags;
    if (flags_ & 0x20)
        f.local20 = 1;
    else if (flags_ & 0x4000)
        f.local20 = (flags_ >> 15) & 7;
    else
        f.local20 = 0;
    f.v64 = flags_ & 0xf;
    PrimGroup *obj;
    f.pal = 0;
    if (a4 != 0 && ((a4->end - a4->begin) >> 6) != 0) {
        void *m = thunk_FUN_0008d690(0x68);
        if (m) {
            f.pal = ((PrimGroupPalette_2e30f0 *)m)->FUN_002dffe0(flags, f18);
            obj = f.pal;
        } else {
            f.pal = 0;
            obj = 0;
        }
    } else {
        void *m = thunk_FUN_0008d690(0x60);
        if (m) {
            f.u12.y12 = flags;
            obj = new (m) pure3d::PrimGroupOptimized(f.u12.y12, f18);
        }
        else
            obj = 0;
    }
    obj->p8(f8);
    obj->f44 = fc;
    FUN_002a46d0(a1, obj);

    Builder *B = 0;
    unsigned char flag = 0;
    if (R->FUN_002669f0()) {
        unsigned int idx = R->FUN_00266a30() - 0x10005;
        if (idx <= 0x17) {
            if (idx == 13 || idx == 15)
                flag = 1;
        }
        f.d.f0 = fc;
        f.d.f4 = flags;
        f.d.c8[3] = 0x20;
        f.d.c8[2] = 0x20;
        f.d.c8[1] = 0x20;
        f.d.c8[0] = 0x20;
        f.d.c8[4] = 0x20;
        f.d.c8[5] = 0x20;
        f.d.c8[6] = 0x20;
        f.d.f10 = f18;
        f.d.f14 = f1c;
        f.d.b19 = 0;
        f.d.f1c = 0;
        f.d.f20 = f20;
        f.d.b18 = flag;
        B = DAT_0052c2a0->f10(&f.d);
        if (B)
            ((Ref_2e30f0 *)B)->AddRef();
        if (obj->f58)
            obj->f58->Release();
        obj->f58 = (Ref_2e30f0 *)B;

        Maker_2e30f0 *mk = DAT_0052c2a8->g89(0x106);
        if (mk) {
            f.u12.hasPal = (a4 != 0);
            if (mk->m4(f8->f10, f.u12.hasPal)) {
                int r = mk->m2(f8->f10, fc, flags, 1, f.u12.y12);
                mk->m5(B, r);
            }
        }
    }

    for (;;) {
        unsigned int idx = R->FUN_00266c30() - 0x10005;
        if (idx <= 0x17) {
            switch (idx) {
            case 0:
                if (flags & 0x2000) {
                    R->stream->FUN_002647e0(&f.n112, 1, 4, 1);
                    AttrList *l = B->b4();
                    for (unsigned int i = f.n112; i > 0; i--) {
                        R->stream->FUN_002647e0(f.v180, 3, 4, 1);
                        l->a0(f.v180[0], f.v180[1], f.v180[2]);
                    }
                    B->b5(l);
                }
                break;
            case 1:
                if (flags & 0x10) {
                    R->stream->FUN_002647e0(&f.n68, 1, 4, 1);
                    AttrList *l = B->b4();
                    for (unsigned int i = f.n68; i > 0; i--) {
                        R->stream->FUN_002647e0(f.v204, 3, 4, 1);
                        l->a1(f.v204[0], f.v204[1], f.v204[2]);
                        l->a17();
                    }
                    B->b5(l);
                }
                break;
            case 2:
                if (flags & 0xf) {
                    unsigned int &A1 = *(unsigned int *)&f.d;
                    R->stream->FUN_002647e0(&A1, 1, 4, 1);
                    R->stream->FUN_002647e0(&f.u12.y12, 1, 4, 1);
                    if (f.u12.y12 < f.v64) {
                        AttrList *l = B->b4();
                        for (unsigned int i = A1; i > 0; i--) {
                            R->stream->FUN_002647e0(f.v160, 2, 4, 1);
                            l->a6(f.v160[0], f.v160[1], f.u12.y12);
                            l->a17();
                        }
                        B->b5(l);
                    }
                }
                break;
            case 3:
                if (flags & 0x20) {
                    R->stream->FUN_002647e0(&f.n88, 1, 4, 1);
                    AttrList *l = B->b4();
                    for (unsigned int i = f.n88; i > 0; i--) {
                        R->stream->FUN_002647e0(&f.v36, 1, 4, 1);
                        l->a4(f.v36, 0);
                        l->a17();
                    }
                    B->b5(l);
                }
                break;
            case 5: {
                R->stream->FUN_002647e0(&f.n40, 1, 4, 1);
                unsigned int n = f.n40;
                unsigned short *buf = (unsigned short *)FUN_00266e00(1, n * 2);
                for (unsigned int i = 0; i < n; i++) {
                    R->stream->FUN_002647e0(&f.v48, 1, 4, 1);
                    buf[i] = (unsigned short)f.v48;
                }
                B->b9(buf, n);
                FUN_00267090(buf);
                break;
            }
            case 6:
                if (flags & 0x80) {
                    R->stream->FUN_002647e0(&f.n64, 1, 4, 1);
                    AttrList *l = B->b4();
                    for (unsigned int i = f.n64; i > 0; i--) {
                        R->stream->FUN_002647e0(&f.v20, 1, 4, 1);
                        l->a10((signed char)(f.v20 >> 24), (signed char)(f.v20 >> 16),
                               (signed char)(f.v20 >> 8), (signed char)f.v20);
                        l->a17();
                    }
                    B->b5(l);
                }
                break;
            case 7:
                if (flags & 0x100) {
                    R->stream->FUN_002647e0(&f.n56, 1, 4, 1);
                    AttrList *l = B->b4();
                    for (unsigned int i = f.n56; i > 0; i--) {
                        R->stream->FUN_002647e0(f.v216, 3, 4, 1);
                        l->a11(f.v216[0], f.v216[1], f.v216[2]);
                        l->a17();
                    }
                    B->b5(l);
                }
                break;
            case 8:
                if (flags & 0x80) {
                    R->stream->FUN_002647e0(&f.n16, 1, 4, 1);
                    pure3d::MatrixPaletteList *mp;
                    void *mm = FUN_0008d690(0x14);
                    if (mm)
                        mp = new (mm) pure3d::MatrixPaletteList();
                    else
                        mp = 0;
                    f.u4.mp = mp;
                    f.zero72 = 0;
                    unsigned int cnt = f.n16;
                    mp->vec.FUN_002e16f0(cnt, &f.zero72);
                    for (unsigned int i = 0; i < f.n16; i++) {
                        R->stream->FUN_002647e0(&f.v80, 1, 4, 1);
                        mp->vec.data[i] = f.v80;
                    }
                    if (a4)
                        a4->AddRef();
                    if (f.pal->f60)
                        f.pal->f60->Release();
                    f.pal->f60 = a4;
                    if (f.u4.mp)
                        f.u4.mp->AddRef();
                    if (f.pal->f64)
                        f.pal->f64->Release();
                    f.pal->f64 = f.u4.mp;
                }
                break;
            case 13: {
                R->stream->FUN_002647e0(&f.c236, 1, 4, 1);
                R->stream->FUN_002647e0(&f.c104, 1, 4, 1);
                R->stream->FUN_002647e0(&f.c52, 1, 4, 1);
                B->b13(R->FUN_00266c30(), f.c104);
                unsigned int c3 = f.c52;
                int *lst = (int *)B->b11(c3);
                R->stream->FUN_002647e0(lst, c3, 1, 1);
                B->b12();
                break;
            }
            case 14: {
                R->stream->FUN_002647e0(&f.c232, 1, 4, 1);
                R->stream->FUN_002647e0(&f.c116, 1, 4, 1);
                R->stream->FUN_002647e0(&f.c60, 1, 4, 1);
                B->b13(R->FUN_00266c30(), f.c116);
                int r = B->b7();
                R->stream->FUN_002647e0((void *)r, f.c60, 1, 1);
                B->b8(f1c);
                break;
            }
            case 15: {
                R->stream->FUN_002647e0(&f.c228, 1, 4, 1);
                R->stream->FUN_002647e0(&f.c84, 1, 4, 1);
                R->stream->FUN_002647e0(&f.c44, 1, 4, 1);
                B->b13(R->FUN_00266c30(), f.c84);
                unsigned int c3 = f.c44;
                int *lst = (int *)B->b11(c3);
                R->stream->FUN_002647e0(lst, c3, 1, 1);
                B->b12();
                break;
            }
            case 16:
                if (flags & 0x1000) {
                    R->stream->FUN_002647e0(&f.n76, 1, 4, 1);
                    AttrList *l = B->b4();
                    for (unsigned int i = f.n76; i > 0; i--) {
                        R->stream->FUN_002647e0(f.v192, 3, 4, 1);
                        l->a3(f.v192[0], f.v192[1], f.v192[2]);
                        l->a17();
                    }
                    B->b5(l);
                }
                break;
            case 17:
                if (flags & 0x800) {
                    R->stream->FUN_002647e0(&f.n108, 1, 4, 1);
                    AttrList *l = B->b4();
                    for (unsigned int i = f.n108; i > 0; i--) {
                        R->stream->FUN_002647e0(f.v168, 3, 4, 1);
                        l->a2(f.v168[0], f.v168[1], f.v168[2]);
                        l->a17();
                    }
                    B->b5(l);
                }
                break;
            case 23:
                if (flags & 0x4000) {
                    R->stream->FUN_002647e0(&f.x92, 1, 4, 1);
                    R->stream->FUN_002647e0(&f.y32, 1, 4, 1);
                    if (f.y32 < f.local20) {
                        AttrList *l = B->b4();
                        for (unsigned int i = f.x92; i > 0; i--) {
                            R->stream->FUN_002647e0(&f.v100, 1, 4, 1);
                            l->a4(f.v100, f.y32);
                            l->a17();
                        }
                        B->b5(l);
                    }
                }
                break;
            default:
                break;
            }
        }
        R->FUN_00266be0();
        if (!R->FUN_002669f0())
            break;
        R->FUN_00266a30();
    }
    B->b6();
}
