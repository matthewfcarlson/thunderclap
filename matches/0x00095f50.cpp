typedef unsigned int u32_95f50;
struct Obj_95f50 {
    u32_95f50 a;
    u32_95f50 b;
};
extern u32_95f50 __cdecl FUN_00267f80();
Obj_95f50* __fastcall FUN_00095f50(Obj_95f50* self) {
    self->a = 0x3a83126f;
    self->b = FUN_00267f80();
    return self;
}