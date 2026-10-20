// STATUS: equivalent (tools/equiv.py level 3: 12546 inputs, branch coverage 2/2)
// FUN_00217790 @ 0x00217790
// FUN_00217790 @ 0x00217790
#include "compat/ptr.h"
struct Buffer { char pad0[8]; char* cursor; char pad1[12]; char* end; char* base; }; void __cdecl FUN_00215460(Buffer*, int); void __cdecl FUN_002159e0(Buffer*, char*, int);
// equiv-conv: FUN_00217790 ecx eax
void FUN_00217790(Buffer* self, char* dest) { hulk_uintptr offset = (hulk_uintptr)dest - (hulk_uintptr)self->base; if ((int)((hulk_uintptr)self->end - (hulk_uintptr)self->cursor) <= 24) FUN_00215460(self, 3); char* old = self->cursor; self->cursor = old + 24; FUN_002159e0(self, old, 1); char* source = self->cursor - 8; self->cursor = source; char* target = self->base + offset; *(unsigned*)target = *(unsigned*)source; *(unsigned*)(target + 4) = *(unsigned*)(source + 4); }
