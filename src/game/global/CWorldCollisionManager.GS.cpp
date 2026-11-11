// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00201740..0x002036c0 (kind game, layer game, confidence high), dominant class CWorldCollisionManager
#include "tree_prelude.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7c6b274 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7c6b274 {} using namespace fn_f7c6b274;
#include "game/global.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *memset(void *dst, int c, unsigned int n);
#endif
namespace fn_f7c6b274 {
class File {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad04[8];
    char ok;
};
class Loader_201850 {
public:
    char pad0[0x284];
    File *file;            // 0x284
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};
struct Rec_201850 {
    char pad0[0x16];
    unsigned short bits;   // 0x16
};
struct Table_201850 {
    char pad0[0x18];
    Rec_201850 *recs;
};
struct Ctx_201850 {
    char pad0[0x44];
    Table_201850 *table;
};
extern "C" char __cdecl FUN_002017d0(char *buf, int *shift, unsigned int *mask);
int __cdecl FUN_00201780(const char *name);
extern "C" void __cdecl FUN_00266f00(int a, void *p);
struct Frame_201850 {
    char pad0[6];          // 0x8 (MSVC aligns this frame struct at 8: the top four bytes of it are the
                           //  original's saved ebx)
    unsigned char len2;    // 0xe
    unsigned char len1;    // 0xf
    unsigned int c;        // 0x10
    union {
        unsigned short *f;
        unsigned int mask;
    } u14;                 // 0x14
    union {
        int a;
        int h;
        unsigned int notC;
    } u18;                 // 0x18
    union {
        int d;
        unsigned short *f2;
    } u1c;                 // 0x1c
    unsigned short flag;   // 0x20
    unsigned short pad22;
    unsigned int e;        // 0x24
    unsigned int e2;       // 0x28
    unsigned int g;        // 0x2c
    int b2;                // 0x30
    int b;                 // 0x34
    char buf[0x100];       // 0x38
    char buf2[0x100];      // 0x138
    int pad238;            // 0x238 (unused)
};


// 0x00201850 FUN_00201850 (857 B): equivalent/0x00201850.cpp
// sym: _FUN_00201850 @b0ec040f3404 @w1d3041f03500
// STATUS: equivalent (tools/equiv.py level 3: 4343 inputs, branch coverage 22/22)
// FUN_00201850 @ 0x00201850
extern "C" void FUN_00201850(Loader_201850 *l, Ctx_201850 *ctx)
{
    Frame_201850 f;
    ((owners::X_2647e0 *)(l->file))->FUN_002647e0((hulk_intptr)(&f.u18.a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(l->file))->FUN_002647e0((hulk_intptr)(&f.u18.a), (hulk_intptr)1, 4, (hulk_intptr)1);
    while (l->FUN_002669f0()) {
        int id = l->FUN_00266a30();
        if (id == 0x7016010) {
            ((owners::X_2647e0 *)(l->file))->FUN_002647e0((hulk_intptr)(&f.b2), (hulk_intptr)1, 4, (hulk_intptr)1);
            memset(f.buf2, 0, 0x100);
            ((owners::X_2647e0 *)(l->file))->FUN_002647e0((hulk_intptr)(&f.len2), (hulk_intptr)1, 1, (hulk_intptr)1);
            unsigned int len = f.len2;
            ((owners::X_2647e0 *)(l->file))->FUN_002647e0((hulk_intptr)(f.buf2), (hulk_intptr)len, 1, (hulk_intptr)1);
            f.buf2[len] = 0;
            f.u18.h = FUN_00201780(f.buf2);
            if (f.u18.h >= 0) {
                ((owners::X_2647e0 *)(l->file))->FUN_002647e0((hulk_intptr)(&f.e2), (hulk_intptr)1, 4, (hulk_intptr)1);
                unsigned int n = f.e2;
                f.u1c.f2 = (unsigned short *)FUN_00266e00(1, n * 2);
                ((owners::X_2647e0 *)(l->file))->FUN_002647e0((hulk_intptr)(f.u1c.f2), (hulk_intptr)n, 2, (hulk_intptr)1);
                f.c = 0;
                if (n != 0) {
                    f.u14.mask = 1 << f.u18.h;
                    do {
                        unsigned short v = f.u1c.f2[f.c];
                        Rec_201850 *r = &ctx->table->recs[v];
                        unsigned int bits = r->bits >> 3;
                        ((owners::X_2647e0 *)(l->file))->FUN_002647e0((hulk_intptr)(&f.flag), (hulk_intptr)1, 2, (hulk_intptr)1);
                        if (f.flag != 0)
                            bits |= f.u14.mask;
                        else
                            bits &= ~f.u14.mask;
                        r->bits = (unsigned short)(bits * 8 | ((unsigned char)r->bits & 7));
                        f.c++;
                    } while (f.c < f.e2);
                }
                FUN_00266f00(1, f.u1c.f2);
            }
        } else if (id == 0x7016012) {
            ((owners::X_2647e0 *)(l->file))->FUN_002647e0((hulk_intptr)(&f.b), (hulk_intptr)1, 4, (hulk_intptr)1);
            memset(f.buf, 0, 0x100);
            ((owners::X_2647e0 *)(l->file))->FUN_002647e0((hulk_intptr)(&f.len1), (hulk_intptr)1, 1, (hulk_intptr)1);
            unsigned int len = f.len1;
            ((owners::X_2647e0 *)(l->file))->FUN_002647e0((hulk_intptr)(f.buf), (hulk_intptr)len, 1, (hulk_intptr)1);
            f.buf[len] = 0;
            f.u1c.d = -1;
            f.c = 0;
            if (FUN_002017d0(f.buf, &f.u1c.d, &f.c)) {
                ((owners::X_2647e0 *)(l->file))->FUN_002647e0((hulk_intptr)(&f.e), (hulk_intptr)1, 4, (hulk_intptr)1);
                unsigned int n = f.e;
                unsigned short *list = (unsigned short *)FUN_00266e00(1, n * 2);
                f.u14.f = list;
                ((owners::X_2647e0 *)(l->file))->FUN_002647e0((hulk_intptr)list, (hulk_intptr)n, 2, (hulk_intptr)1);
                unsigned int i = 0;
                if (f.e != 0) {
                    f.u18.notC = ~f.c;
                    do {
                        ((owners::X_2647e0 *)(l->file))->FUN_002647e0((hulk_intptr)(&f.g), (hulk_intptr)1, 2, (hulk_intptr)1);
                        Rec_201850 *r = &ctx->table->recs[f.u14.f[i]];
                        unsigned int old = r->bits;
                        unsigned int val = ((f.g << f.u1c.d) & f.c) << 3;
                        val |= ((f.u18.notC << 3) | 7) & old;
                        r->bits = (unsigned short)val;
                        i++;
                    } while (i < f.e);
                }
                FUN_00266f00(1, f.u14.f);
            }
        }
        l->FUN_00266be0();
    }
}

} // namespace fn_f7c6b274
