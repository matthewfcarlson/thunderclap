typedef unsigned int u32_104a70;
void thunk_FUN_00267090(u32_104a70);
struct Obj_104a70 {
    u32_104a70 a;
    char pad[8];
    u32_104a70 b;
};
void __fastcall FUN_00104a70(Obj_104a70* self) {
    thunk_FUN_00267090(self->a);
    thunk_FUN_00267090(self->b);
}