// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002ffee0 @ 0x002ffee0
#include "compat/ptr.h"
extern "C" void * __cdecl bsearch(const void *, const void *, unsigned, unsigned, int (__cdecl *)(const void *, const void *));
int __cdecl FUN_002feae0(const void *, const void *);
struct Entry { int *begin; int *end; char rest[0x64]; };
struct Search { Entry *entries; int count; };
// equiv-conv: FUN_002ffee0 ecx eax stack
unsigned FUN_002ffee0(Search *self, unsigned originalEax, int key) {
    if (self->count <= 0) return originalEax & ~255u;
    for (int i = 0; i < self->count; ++i) {
        Entry &e = self->entries[i];
        int query = key;
        void *found = bsearch(&query, e.begin, e.end - e.begin, 4, FUN_002feae0);
        if (found) return ((hulk_uintptr)found & ~255u) | 1;
    }
    return self->count & ~255u;
}