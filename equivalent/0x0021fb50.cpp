// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 17/18, incomplete)
// FUN_0021fb50 @ 0x0021fb50
// FUN_0021fb50 @ 0x0021fb50
#include "compat/ptr.h"
struct State;
struct Zio;
struct Buffer;
struct Str;

struct LocVar_21fb50 {
    Str *name;
    int startpc;
    int endpc;
};

struct Proto_21fb50 {
    char pad0[0x18];
    LocVar_21fb50 *locvars;
    char pad1[0x38 - 0x1c];
    int nlocvars;
};

struct Reader {
    State *L;
    Zio *zio;
    Buffer *buf;
};

// equiv-conv: FUN_0021f8c0 ecx eax edx
void FUN_0021f8c0(void *dst, int size, Reader *r);
// equiv-conv: FUN_0021f800 esi stack
void FUN_0021f800(Reader *r, const char *msg);
void *FUN_0021add0(State *L, void *block, unsigned int oldSize, unsigned int newSize);
char *FUN_0021a6b0(State *L, Buffer *buf, hulk_uintptr n);
int FUN_0021a610(Zio *z, char *dst, hulk_uintptr n);
Str *FUN_00219430(State *L, const char *s, hulk_uintptr len);

struct Frame_21fb50 {
    int w;
    int count;
    hulk_uintptr size;
    char *s;
    int pad;
    int v;
};

// equiv-conv: FUN_0021fb50 eax stack
void FUN_0021fb50(Reader *r, Proto_21fb50 *p)
{
    Frame_21fb50 f;
    FUN_0021f8c0(&f.v, 4, r);
    if (f.v < 0) {
        FUN_0021f800(r, "bad integer");
    }
    int n = f.v;
    p->locvars = (LocVar_21fb50 *)FUN_0021add0(r->L, 0, 0, n * 12);
    p->nlocvars = n;
    int i;
    for (i = 0; i < n; i++)
        p->locvars[i].name = 0;
    f.count = n;
    for (i = 0; i < n; i++) {
        FUN_0021f8c0(&f.size, 4, r);
        Str *name = (Str *)f.size;
        if (f.size != 0) {
            f.s = FUN_0021a6b0(r->L, r->buf, f.size);
            if (FUN_0021a610(r->zio, f.s, f.size))
                FUN_0021f800(r, "unexpected end of file");
            name = FUN_00219430(r->L, f.s, f.size - 1);
        }
        p->locvars[i].name = name;
        FUN_0021f8c0(&f.v, 4, r);
        if (f.v < 0)
            FUN_0021f800(r, "bad integer");
        p->locvars[i].startpc = f.v;
        FUN_0021f8c0(&f.w, 4, r);
        if (f.w < 0)
            FUN_0021f800(r, "bad integer");
        p->locvars[i].endpc = f.w;
    }
}
