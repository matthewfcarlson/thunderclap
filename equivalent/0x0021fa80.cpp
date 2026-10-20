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
void FUN_0021f8c0(void *dst, int size, Reader *r);
// equiv-conv: FUN_0021f800 esi stack
void FUN_0021f800(Reader *r, const char *msg);
char *FUN_0021a6b0(State *L, Buffer *buf, hulk_uintptr n);
int FUN_0021a610(Zio *z, char *dst, hulk_uintptr n);
Str *FUN_00219430(State *L, const char *s, hulk_uintptr len);

// equiv-conv: FUN_0021fa80 eax
Str *FUN_0021fa80(Reader *r)
{
    unsigned int size;
    FUN_0021f8c0(&size, 4, r);
    if (size == 0)
        return 0;
    char *s = FUN_0021a6b0(r->L, r->buf, size);
    if (FUN_0021a610(r->zio, s, size))
        FUN_0021f800(r, "unexpected end of file");
    return FUN_00219430(r->L, s, size - 1);
}
