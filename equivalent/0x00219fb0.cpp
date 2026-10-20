// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 6/6)
// FUN_00219fb0 @ 0x00219fb0
// FUN_00219fb0 @ 0x00219fb0
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"

struct Context { char pad0[16]; unsigned int base; char pad1[8]; int index; };
// equiv-conv: FUN_00219980 esi stack
extern int __cdecl FUN_00219980(int* key, float value);
extern float* __cdecl FUN_00219e90(Context* ctx, int* key);
extern void __cdecl FUN_00214a90(void* receiver, const char* message);
// equiv-conv: FUN_00219fb0 eax edi stack
hulk_intptr FUN_00219fb0(int* key, Context* ctx, void* receiver)
{
    if (*key == 0) return -1;
    int position = FUN_00219980(key, (float)ctx->index);
    if (position >= 0) return position - 1;
    float* entry = FUN_00219e90(ctx, key);
    if (entry == ((float*)&DAT_00426824))
        FUN_00214a90(receiver, "invalid key for `next'");
    return ((hulk_uintptr)entry - ctx->base - 8) / 20 + ctx->index;
}
