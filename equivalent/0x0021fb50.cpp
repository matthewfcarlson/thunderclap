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
extern "C" void __cdecl FUN_0021f8c0(char *, unsigned int, void *);
// equiv-conv: FUN_0021f800 esi stack
void FUN_0021f800(Reader *r, const char *msg);
void *FUN_0021add0(State *L, void *block, unsigned int oldSize, unsigned int newSize);
extern "C" void * __cdecl FUN_0021a6b0(void *, void **, hulk_uintptr);
extern "C" unsigned int __cdecl FUN_0021a610(void *, void *, unsigned int);
Str *FUN_00219430(State *L, const char *s, unsigned int len);

struct Frame_21fb50 {
    int w;
    int count;
    hulk_uintptr size;
    char *s;
    int pad;
    int v;
};

// equiv-conv: FUN_0021fb50 eax stack
extern "C" void FUN_0021fb50(void *r, void *p)
{
    Frame_21fb50 f;
    FUN_0021f8c0((char *)(void *)(&f.v), 4, (Reader *)((Reader *)r));
    if (f.v < 0) {
        FUN_0021f800(((Reader *)r), "bad integer");
    }
    int n = f.v;
    ((Proto_21fb50 *)p)->locvars = (LocVar_21fb50 *)FUN_0021add0(((Reader *)r)->L, 0, 0, n * 12);
    ((Proto_21fb50 *)p)->nlocvars = n;
    int i;
    for (i = 0; i < n; i++)
        ((Proto_21fb50 *)p)->locvars[i].name = 0;
    f.count = n;
    for (i = 0; i < n; i++) {
        FUN_0021f8c0((char *)(void *)(&f.size), 4, (Reader *)((Reader *)r));
        Str *name = (Str *)f.size;
        if (f.size != 0) {
            f.s = ((char *)FUN_0021a6b0((State *)(((Reader *)r)->L), (void **)(Buffer *)(((Reader *)r)->buf), f.size));
            if (((int)FUN_0021a610((Zio *)(((Reader *)r)->zio), (char *)(f.s), (hulk_uintptr)(f.size))))
                FUN_0021f800(((Reader *)r), "unexpected end of file");
            name = FUN_00219430(((Reader *)r)->L, f.s, f.size - 1);
        }
        ((Proto_21fb50 *)p)->locvars[i].name = name;
        FUN_0021f8c0((char *)(void *)(&f.v), 4, (Reader *)((Reader *)r));
        if (f.v < 0)
            FUN_0021f800(((Reader *)r), "bad integer");
        ((Proto_21fb50 *)p)->locvars[i].startpc = f.v;
        FUN_0021f8c0((char *)(void *)(&f.w), 4, (Reader *)((Reader *)r));
        if (f.w < 0)
            FUN_0021f800(((Reader *)r), "bad integer");
        ((Proto_21fb50 *)p)->locvars[i].endpc = f.w;
    }
}
