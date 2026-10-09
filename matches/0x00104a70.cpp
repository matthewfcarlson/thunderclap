typedef unsigned int u32;
void thunk_FUN_00267090(u32);
struct Obj { u32 a; char pad[8]; u32 b; };
void __fastcall FUN_00104a70(Obj* self) { thunk_FUN_00267090(self->a); thunk_FUN_00267090(self->b); }