struct Obj_2789e0 {
    char pad[0xb4];
    int value;
};
extern int __stdcall FUN_002787c0(int);
bool __fastcall target(Obj_2789e0* self, void*, int arg) {
    int result = FUN_002787c0(arg);
    self->value = result;
    return result == 0;
}