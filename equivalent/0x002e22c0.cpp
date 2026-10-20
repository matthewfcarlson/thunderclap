// STATUS: equivalent (tools/equiv.py level 3: 2785 inputs, branch coverage 121/122, incomplete)
// FUN_002e22c0 @ 0x002e22c0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-map: ??0PrimGroup@pure3d@@QAE@HHH@Z = 0x002e01d0
#include "decls/address.h"
inline void *operator new(unsigned int, void *p) { return p; }

void *thunk_FUN_0008d690(unsigned int size);
void *__cdecl FUN_0008d690(unsigned int size);

struct Stream {
    int FUN_002647e0(void *buf, int count, int size, int flag);
};

class Reader {
public:
    char pad0[0x284];
    Stream *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct IntVec_2e22c0 {
    int *begin;
    int fc;
    void FUN_002e16f0(unsigned int n, int *fill);
};

namespace pure3d {

class PrimGroup {
public:
    PrimGroup(int a, int b, int c);
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int a);
    char pad04[0x44 - 4];
    int f44;
    char pad48[8];
    int f50;
    char pad54[4];
    int f58;
    struct Dest_2e22c0 *f5c;
};

class RefObj_2e22c0 {
public:
    virtual void AddRef();
    virtual void Release();
};

class PrimGroupSkinnedStreamed : public PrimGroup {
public:
    PrimGroupSkinnedStreamed(int a, int b, int c) : PrimGroup(a, b, c)
    {
        f60 = 0;
        f64 = 0;
    }
    RefObj_2e22c0 *f60;
    RefObj_2e22c0 *f64;
};

class MatrixPaletteList : public RefObj_2e22c0 {
public:
    MatrixPaletteList()
    {
        f4 = 0;
        arr.begin = 0;
        arr.fc = 0;
    }
    int f4;
    IntVec_2e22c0 arr;
    int f10;
};

}

struct Dest_2e22c0 {
    // (the vftable pointer is the first 4 bytes; the fields below are at the original's offsets)
    char pad4[8];
    int fc;
    char pad10[4];
    unsigned short *f14;
    void *f18;
    void *f1c;
    void *f20;
    char pad24[4];
    void *f28;
    char pad2c[4];
    void *f30;
    char pad34[4];
    void *arr38[4];     // 0x38
    void *arr48[2];     // 0x48
    unsigned char *f50;
    char *f54;
    void FUN_002c7120();
    void FUN_002c71b0();
    void FUN_002c7240(int i);
    void FUN_002c72e0(int i);
    void FUN_002c7070();
    Dest_2e22c0 *FUN_002c8460(int a);
    virtual void v0();
    virtual void v1();
};

struct Obj60_2e22c0 {
    char pad0[0x50];
    int f50;
    char pad54[8];
    Dest_2e22c0 *f5c;
    Obj60_2e22c0 *FUN_002e0760(pure3d::PrimGroup *b);
};

class Hub89 {
public:
    virtual void v0();
};

struct Aux_2e22c0 {
    virtual void a0();
    virtual void a1();
    virtual int a2(int a, int b, int c, int d, int e);
    virtual void a3();
    virtual char a4(int a, int b);
};

class Gfx {
public:
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual void h4();
    virtual void h5();
    virtual void h6();
    virtual void h7();
    virtual void h8();
    virtual void h9();
    virtual void h10();
    virtual void h11();
    virtual void h12();
    virtual void h13();
    virtual void h14();
    virtual void h15();
    virtual void h16();
    virtual void h17();
    virtual void h18();
    virtual void h19();
    virtual void h20();
    virtual void h21();
    virtual void h22();
    virtual void h23();
    virtual void h24();
    virtual void h25();
    virtual void h26();
    virtual void h27();
    virtual void h28();
    virtual void h29();
    virtual void h30();
    virtual void h31();
    virtual void h32();
    virtual void h33();
    virtual void h34();
    virtual void h35();
    virtual void h36();
    virtual void h37();
    virtual void h38();
    virtual void h39();
    virtual void h40();
    virtual void h41();
    virtual void h42();
    virtual void h43();
    virtual void h44();
    virtual void h45();
    virtual void h46();
    virtual void h47();
    virtual void h48();
    virtual void h49();
    virtual void h50();
    virtual void h51();
    virtual void h52();
    virtual void h53();
    virtual void h54();
    virtual void h55();
    virtual void h56();
    virtual void h57();
    virtual void h58();
    virtual void h59();
    virtual void h60();
    virtual void h61();
    virtual void h62();
    virtual void h63();
    virtual void h64();
    virtual void h65();
    virtual void h66();
    virtual void h67();
    virtual void h68();
    virtual void h69();
    virtual void h70();
    virtual void h71();
    virtual void h72();
    virtual void h73();
    virtual void h74();
    virtual void h75();
    virtual void h76();
    virtual void h77();
    virtual void h78();
    virtual void h79();
    virtual void h80();
    virtual void h81();
    virtual void h82();
    virtual void h83();
    virtual void h84();
    virtual void h85();
    virtual void h86();
    virtual void h87();
    virtual void h88();
    virtual Aux_2e22c0 *h89(int a);
};

struct Holder10_2e22c0 {
    char pad0[0x10];
    int f10;
};

struct VecObj {
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    int f8;
    int fc;
};


struct Frame_2e22c0 {
    void *self;                                 // 0x00
    pure3d::PrimGroup *B;                       // 0x04
    int x8;                                     // 0x08
    pure3d::PrimGroupSkinnedStreamed *psk;      // 0x0c
    pure3d::MatrixPaletteList *mpl;             // 0x10
    int nuv;                                    // 0x14
    int x18, x1c, x20, x24, x28, x2c;           // 0x18..0x2c
    int nlow;                                   // 0x30
    int x34, x38, x3c, x40, x44, x48, x4c, x50, x54, x58;
};

class Loader_2e22c0 {
public:
    char pad0[8];
    Holder10_2e22c0 *f8;
    int fc;
    char pad10[2];
    unsigned short w12;
    int f14;
    char pad18[4];
    unsigned int f1c;
    int f20;
    int f24;
    void FUN_002a46d0(void *a0, void *obj);
    void FUN_002a4b00(void *a0, Reader *rd, int a2);
    void FUN_002e22c0(void *a0, Reader *rd, int a2, VecObj *a3, int a4);
};

void Loader_2e22c0::FUN_002e22c0(void *a0, Reader *rd, int a2, VecObj *a3, int a4)
{
    Frame_2e22c0 fr;
    unsigned int flags = f1c;
    Dest_2e22c0 *D;
    fr.self = this;
    fr.psk = 0;

    if (flags & 0x20)
        fr.nuv = 1;
    else if (flags & 0x4000)
        fr.nuv = (flags >> 15) & 7;
    else
        fr.nuv = 0;
    fr.nlow = flags & 0xf;

    if (a3 != 0 && ((a3->fc - a3->f8) >> 6) != 0) {
        void *mem = thunk_FUN_0008d690(0x68);
        if (mem != 0) {
            fr.psk = new (mem) pure3d::PrimGroupSkinnedStreamed(f1c, f20, f24);
            fr.B = fr.psk;
        } else {
            fr.psk = 0;
            fr.B = 0;
        }
    } else {
        void *mem = thunk_FUN_0008d690(0x60);
        if (mem != 0)
            fr.B = new (mem) pure3d::PrimGroup(f1c, f20, f24);
        else
            fr.B = 0;
    }
    fr.B->v8((int)f8);
    fr.B->f44 = fc;

    if (w12 == 1) {
        Obj60_2e22c0 *N = 0;
        void *mem = thunk_FUN_0008d690(0x60);
        if (mem != 0)
            N = ((Obj60_2e22c0 *)mem)->FUN_002e0760(fr.B);
        void *m30 = FUN_0008d690(0x30);
        Dest_2e22c0 *d30;
        if (m30 != 0)
            d30 = ((Dest_2e22c0 *)m30)->FUN_002c8460(f20);
        else
            d30 = 0;
        N->f5c = d30;
        d30->v0();
        N->f50 = f14;
        if (f14 & 0x10)
            N->f5c->FUN_002c7120();
        if (f14 & 0x20)
            N->f5c->FUN_002c71b0();
        unsigned int i;
        for (i = 0; i < 4; i++) {
            if (f14 & (1 << i))
                N->f5c->FUN_002c7240(i);
        }
        for (i = 0; i < 2; i++) {
            if (f14 & (0x40 << i))
                N->f5c->FUN_002c72e0(i);
        }
        N->f5c->FUN_002c7070();
        FUN_002a46d0(a0, N);
    } else if (w12 == 2) {
        ((Obj60_2e22c0 *)fr.B)->f50 = f14;
        FUN_002a46d0(a0, fr.B);
    } else {
        FUN_002a46d0(a0, fr.B);
    }
    {
        Aux_2e22c0 *aux = DAT_0052c2a8->h89(0x106);
        if (aux != 0) {
            if (aux->a4(f8->f10, 0))
                fr.B->f58 = aux->a2(f8->f10, fc, f1c & 0xfffffe7f, 0, 0);
        }
    }
    Reader *ebp = rd;
    D = ((Obj60_2e22c0 *)fr.B)->f5c;
    if (!ebp->FUN_002669f0())
        return;
    do {
        int k = ebp->FUN_00266a30();
        if (k > 0x1001c) {
            if (k == 0x121204)
                FUN_002a4b00(a0, ebp, a2);
        } else if (k == 0x1001c) {
            if (f1c & 0x4000) {
                ebp->stream->FUN_002647e0(&fr.x58, 1, 4, 1);
                ebp->stream->FUN_002647e0(&fr.x54, 1, 4, 1);
                if ((unsigned int)fr.x54 < (unsigned int)fr.nuv)
                    ebp->stream->FUN_002647e0(D->arr48[fr.x54], fr.x58, 4, 1);
            }
        } else {
            switch (k) {
            case 0x10003:
                ebp->stream->FUN_002647e0((char *)fr.B + 0x14, 3, 4, 1);
                ebp->stream->FUN_002647e0((char *)fr.B + 0x20, 3, 4, 1);
                break;
            case 0x10004:
                ebp->stream->FUN_002647e0((char *)fr.B + 0x2c, 3, 4, 1);
                ebp->stream->FUN_002647e0(&fr.x50, 1, 4, 1);
                *(int *)((char *)fr.B + 0x38) = fr.x50;
                break;
            case 0x10005:
                if (f1c & 0x2000) {
                    ebp->stream->FUN_002647e0(&fr.x18, 1, 4, 1);
                    ebp->stream->FUN_002647e0(D->f18, fr.x18 * 3, 4, 1);
                    if ((signed char)f1c < 0) {
                        void *dst = D->f20;
                        if (dst != 0) {
                            unsigned int n = D->fc * 12;
                            char *s = (char *)D->f18;
                            char *dd = (char *)dst;
                            unsigned int j;
                            for (j = 0; j < n; j++)
                                dd[j] = s[j];
                        }
                    }
                }
                break;
            case 0x10006:
                if (f1c & 0x10) {
                    ebp->stream->FUN_002647e0(&fr.x1c, 1, 4, 1);
                    ebp->stream->FUN_002647e0(D->f1c, fr.x1c * 3, 4, 1);
                }
                break;
            case 0x10007:
                if (f1c & 0xf) {
                    ebp->stream->FUN_002647e0(&fr.x34, 1, 4, 1);
                    ebp->stream->FUN_002647e0(&fr.x2c, 1, 4, 1);
                    if ((unsigned int)fr.x2c < (unsigned int)fr.nlow)
                        ebp->stream->FUN_002647e0(D->arr38[fr.x2c], fr.x34 * 2, 4, 1);
                }
                break;
            case 0x10008:
                if (f1c & 0x20) {
                    ebp->stream->FUN_002647e0(&fr.x28, 1, 4, 1);
                    ebp->stream->FUN_002647e0(D->arr48[0], fr.x28, 4, 1);
                }
                break;
            case 0x1000a: {
                ebp->stream->FUN_002647e0(&fr.x38, 1, 4, 1);
                unsigned int cnt = fr.x38;
                unsigned int i;
                for (i = 0; i < cnt; i++) {
                    ebp->stream->FUN_002647e0(&fr.x3c, 1, 4, 1);
                    D->f14[i] = (unsigned short)fr.x3c;
                }
                break;
            }
            case 0x1000b:
                if ((signed char)f1c < 0) {
                    ebp->stream->FUN_002647e0(&fr.x44, 1, 4, 1);
                    unsigned int cnt = fr.x44;
                    unsigned int i;
                    for (i = 0; i < cnt; i++) {
                        ebp->stream->FUN_002647e0(&rd, 1, 4, 1);
                        D->f50[i * 4] = (unsigned char)(*(unsigned int *)&rd >> 24);
                        D->f50[i * 4 + 1] = (unsigned char)(*(unsigned int *)&rd >> 16);
                        D->f50[i * 4 + 2] = (unsigned char)(*(unsigned int *)&rd >> 8);
                        D->f50[i * 4 + 3] = (unsigned char)*(unsigned int *)&rd;
                    }
                }
                break;
            case 0x1000c:
                if (f1c & 0x100) {
                    ebp->stream->FUN_002647e0(&fr.x40, 1, 4, 1);
                    unsigned int cnt = fr.x40;
                    if (cnt != 0) {
                        int off = 0;
                        do {
                            ebp->stream->FUN_002647e0(D->f54 + off, 3, 4, 1);
                            off += 12;
                        } while (--cnt != 0);
                    }
                }
                break;
            case 0x1000d:
                if ((signed char)f1c < 0) {
                    ebp->stream->FUN_002647e0(&fr.x8, 1, 4, 1);
                    void *mem = FUN_0008d690(0x14);
                    if (mem != 0)
                        fr.mpl = new (mem) pure3d::MatrixPaletteList();
                    else
                        fr.mpl = 0;
                    fr.x48 = 0;
                    fr.mpl->arr.FUN_002e16f0(fr.x8, &fr.x48);
                    unsigned int i;
                    for (i = 0; i < (unsigned int)fr.x8; i++) {
                        ebp->stream->FUN_002647e0(&fr.x4c, 1, 4, 1);
                        fr.mpl->arr.begin[i] = fr.x4c;
                    }
                    if (a3 != 0)
                        a3->AddRef();
                    if (fr.psk->f60 != 0)
                        fr.psk->f60->Release();
                    fr.psk->f60 = (pure3d::RefObj_2e22c0 *)a3;
                    if (fr.mpl != 0)
                        fr.mpl->AddRef();
                    if (fr.psk->f64 != 0)
                        fr.psk->f64->Release();
                    fr.psk->f64 = fr.mpl;
                }
                break;
            case 0x10015:
                if (f1c & 0x1000) {
                    ebp->stream->FUN_002647e0(&fr.x24, 1, 4, 1);
                    ebp->stream->FUN_002647e0(D->f30, fr.x24 * 3, 4, 1);
                }
                break;
            case 0x10016:
                if (f1c & 0x800) {
                    ebp->stream->FUN_002647e0(&fr.x20, 1, 4, 1);
                    ebp->stream->FUN_002647e0(D->f28, fr.x20 * 3, 4, 1);
                }
                break;
            default:
                break;
            }
        }
        ebp->FUN_00266be0();
    } while (ebp->FUN_002669f0());
}
