// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 4/4)
// FUN_00240090 @ 0x00240090
#include "compat/ptr.h"
void __cdecl FUN_0023fa40(int* out, hulk_intptr text, int a, int b);

struct Handle_240090 {
    hulk_intptr text;                   // 0x00
    unsigned short kind;        // 0x04
    unsigned short pad6;
    unsigned short extra;       // 0x08
    void FUN_00240090(const Handle_240090* other);
};

// Copy-constructs a handle: kind 0 is copied as is, kind 1 is converted through FUN_0023fa40
// (which writes its result over the incoming argument slot), anything else shares the text and
// bumps its reference count.
void Handle_240090::FUN_00240090(const Handle_240090* other)
{
    const Handle_240090* src = other;
    unsigned short k = src->kind;
    if (k == 0) {
        text = src->text;
        kind = 0;
        extra = src->extra;
    } else if (k == 1) {
        unsigned int e = src->extra;
        kind = 2;
        extra = (unsigned short)e;
        FUN_0023fa40((int*)&other, src->text, e, e);
        text = (hulk_intptr)other;
        extra = src->extra;
    } else {
        kind = 2;
        text = src->text;
        extra = src->extra;
        (*(unsigned short*)(text - 4))++;
    }
}
