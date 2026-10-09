typedef unsigned int u32;
void __cdecl FUN_00212d80(u32, int);
struct Obj {
    char pad[8];
    u32 value;
};
void __fastcall target(Obj* self, int arg, int extra) {
    FUN_00212d80(self->value, 0);
}