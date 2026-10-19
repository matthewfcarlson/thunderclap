// STATUS: equivalent (tools/equiv.py level 3: 2876 inputs, branch coverage 2/2)
// FUN_00217790 @ 0x00217790
struct Buffer { char pad0[8]; char* cursor; char pad1[12]; char* end; char* base; }; void __cdecl FUN_00215460(Buffer*, int); void __cdecl FUN_002159e0(Buffer*, char*, int);
// equiv-conv: FUN_00217790 ecx eax
void FUN_00217790(Buffer* self, char* dest) { unsigned offset = (unsigned)dest - (unsigned)self->base; if ((int)((unsigned)self->end - (unsigned)self->cursor) <= 24) FUN_00215460(self, 3); char* old = self->cursor; self->cursor = old + 24; FUN_002159e0(self, old, 1); char* source = self->cursor - 8; self->cursor = source; char* target = self->base + offset; *(unsigned*)target = *(unsigned*)source; *(unsigned*)(target + 4) = *(unsigned*)(source + 4); }