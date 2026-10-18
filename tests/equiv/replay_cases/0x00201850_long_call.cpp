// STATUS: equivalent (tools/equiv.py level 3: 16486 inputs, branch coverage 22/22)
// FUN_00201850 @ 0x00201850
extern "C" void *memset(void *dst, int c, unsigned int n);
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int cookie);

class File {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad04[8];
    char ok;
    void FUN_002647e0(void *out, int a, int b, int c);
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

char __cdecl FUN_002017d0(char *buf, int *shift, unsigned int *mask);
int __cdecl FUN_00201780(const char *name);
void *__cdecl FUN_00266e00(int a, int bytes);
void __cdecl FUN_00266f00(int a, void *p);

// The original's frame (and esp,-8; sub esp,0x234), laid out from the 8-aligned top down; the comments give
// [esp+N] in the original after its three register pushes.
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
    unsigned int cookie;   // 0x23c
};

void FUN_00201850(Loader_201850 *l, Ctx_201850 *ctx)
{
    Frame_201850 f;
    f.cookie = DAT_004d9968;
    l->file->FUN_002647e0(&f.u18.a, 1, 4, 1);
    l->file->FUN_002647e0(&f.u18.a, 1, 4, 1);
    while (l->FUN_002669f0()) {
        int id = l->FUN_00266a30();
        if (id == 0x7016010) {
            l->file->FUN_002647e0(&f.b2, 1, 4, 1);
            memset(f.buf2, 0, 0x100);
            l->file->FUN_002647e0(&f.len2, 1, 1, 1);
            unsigned int len = f.len2;
            l->file->FUN_002647e0(f.buf2, len, 1, 1);
            f.buf2[len] = 0;
            f.u18.h = FUN_00201780(f.buf2);
            if (f.u18.h >= 0) {
                l->file->FUN_002647e0(&f.e2, 1, 4, 1);
                unsigned int n = f.e2;
                f.u1c.f2 = (unsigned short *)FUN_00266e00(1, n * 2);
                l->file->FUN_002647e0(f.u1c.f2, n, 2, 1);
                f.c = 0;
                if (n != 0) {
                    f.u14.mask = 1 << f.u18.h;
                    do {
                        unsigned short v = f.u1c.f2[f.c];
                        Rec_201850 *r = &ctx->table->recs[v];
                        unsigned int bits = r->bits >> 3;
                        l->file->FUN_002647e0(&f.flag, 1, 2, 1);
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
            l->file->FUN_002647e0(&f.b, 1, 4, 1);
            memset(f.buf, 0, 0x100);
            l->file->FUN_002647e0(&f.len1, 1, 1, 1);
            unsigned int len = f.len1;
            l->file->FUN_002647e0(f.buf, len, 1, 1);
            f.buf[len] = 0;
            f.u1c.d = -1;
            f.c = 0;
            if (FUN_002017d0(f.buf, &f.u1c.d, &f.c)) {
                l->file->FUN_002647e0(&f.e, 1, 4, 1);
                unsigned int n = f.e;
                unsigned short *list = (unsigned short *)FUN_00266e00(1, n * 2);
                f.u14.f = list;
                l->file->FUN_002647e0(list, n, 2, 1);
                unsigned int i = 0;
                if (f.e != 0) {
                    f.u18.notC = ~f.c;
                    do {
                        l->file->FUN_002647e0(&f.g, 1, 2, 1);
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
    __security_check_cookie(f.cookie);
}
