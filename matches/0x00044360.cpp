struct Obj {
    char pad[0x3b0];
};
Obj* __fastcall FUN_00044360(Obj* self) {
    return (Obj*)((char*)self + 0x3b0);
}