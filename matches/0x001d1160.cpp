typedef unsigned int u32_1d1160;
void __cdecl FUN_00212d80(u32_1d1160, int);
struct Obj_1d1160 {
    char pad[8];
    u32_1d1160 value;
};
void __fastcall target(Obj_1d1160* self, int arg, int extra) {
    FUN_00212d80(self->value, 0);
}