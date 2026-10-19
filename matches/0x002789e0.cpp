struct Obj_2789e0 {
    char pad[0xb4];
    int value;
};
struct ThisCall_002787c0 {
    int FUN_002787c0(int);
};
bool __fastcall target(Obj_2789e0* self, void*, int arg) {
    int result = ((ThisCall_002787c0*)(self))->FUN_002787c0(arg);
    self->value = result;
    return result == 0;
}