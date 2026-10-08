typedef unsigned int u32;
struct Obj { u32 a; u32 b; };
extern u32 __cdecl FUN_00267f80();
Obj* __fastcall FUN_00095f50(Obj* self) {
    self->a = 0x3a83126f;
    self->b = FUN_00267f80();
    return self;
}