// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_0021fa80 @ 0x0021fa80
// FUN_0021fa80 @ 0x0021fa80
#include "compat/ptr.h"
struct State;
struct Zio;
struct Buffer;
struct Str;

struct Reader {
    State *L;
    Zio *zio;
    Buffer *buf;
};

// equiv-conv: FUN_0021f8c0 ecx eax edx
extern "C" void __cdecl FUN_0021f8c0(char *, unsigned int, void *);
// equiv-conv: FUN_0021f800 esi stack
void FUN_0021f800(Reader *r, const char *msg);
extern "C" void * __cdecl FUN_0021a6b0(void *, void **, hulk_uintptr);
extern "C" unsigned int __cdecl FUN_0021a610(void *, void *, unsigned int);
Str *FUN_00219430(State *L, const char *s, unsigned int len);

// equiv-conv: FUN_0021fa80 eax
extern "C" Str *FUN_0021fa80(Reader *r)
{
    unsigned int size;
    FUN_0021f8c0((char *)(void *)(&size), 4, (Reader *)r);
    if (size == 0)
        return 0;
    char *s = ((char *)FUN_0021a6b0((State *)(r->L), (void **)(Buffer *)(r->buf), size));
    if (((int)FUN_0021a610((Zio *)(r->zio), (char *)s, (hulk_uintptr)size)))
        FUN_0021f800(r, "unexpected end of file");
    return FUN_00219430(r->L, s, size - 1);
}
