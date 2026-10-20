// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002153d0 @ 0x002153d0
#include "compat/ptr.h"
struct Buffer { char pad[0x18]; char* end; char* data; int capacity; };
extern "C" char* __cdecl FUN_0021add0(Buffer*, char*, hulk_intptr, hulk_intptr);
// equiv-conv: FUN_00215350 eax edx
extern "C" int FUN_00215350(Buffer*, char*);
int __cdecl FUN_002153d0(Buffer* b, int count)
{
    char* oldData = b->data;
    char* data = FUN_0021add0(b, oldData, b->capacity * 8, count * 8);
    b->end = data + count * 8 - 0x30;
    b->data = data;
    b->capacity = count;
    return FUN_00215350(b, oldData);
}
