// STATUS: equivalent (tools/equiv.py level 3: 168 inputs, branch coverage 14/14)
// FUN_002eb330 @ 0x002eb330
#include "compat/ptr.h"
// the original scans and copies with inline repne scasb / rep movs; plain forward loops keep clang from emitting calls
static inline unsigned int Len(const char *p) { const char *q = p; while (*q) q++; return (unsigned int)(q - p); }
static inline void Copy(char *d, const char *p, unsigned int n) {
    // rep movsd for the whole dwords, then rep movsb for the rest (the order matters when the ranges overlap)
    unsigned int w = n >> 2;
    while (w--) { *(unsigned int *)d = *(const unsigned int *)p; d += 4; p += 4; }
    for (unsigned int k = n & 3; k; k--) *d++ = *p++;
}

struct Pool;

void *FUN_002e6c00(Pool *pool, hulk_uintptr size);

struct Entry_2eb330 {
    char pad0[8];
    unsigned int flags;
    char padc[0xa0 - 0xc];
    char *name;
    int a4;
    int a8;
    char *text;
    char **list;
    unsigned char flagA;
    unsigned char count;
};

void FUN_002eb330(Pool *pool, Entry_2eb330 *e, const char *name, int a4, int a8,
                  char flagA, int count, const char *text, const char **list)
{
    if (pool == 0)
        return;
    if (e == 0)
        return;

    hulk_uintptr n = Len(name) + 1;
    char *copy = (char *)FUN_002e6c00(pool, n);
    e->name = copy;
    Copy(copy, name, n);
    e->flagA = flagA;
    e->a4 = a4;
    e->a8 = a8;
    e->count = (unsigned char)count;

    n = Len(text) + 1;
    copy = (char *)FUN_002e6c00(pool, n);
    e->text = copy;
    Copy(copy, text, n);

    e->list = (char **)FUN_002e6c00(pool, count * 4 + 4);
    e->list[count] = 0;
    for (int i = 0; i < count; i++) {
        n = Len(list[i]) + 1;
        char *s = (char *)FUN_002e6c00(pool, n);
        e->list[i] = s;
        Copy(e->list[i], list[i], n);
    }
    e->flags |= 0x400;
}
