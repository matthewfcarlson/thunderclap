struct Obj {
    char pad[0x24];
};
Obj* __fastcall FUN_00092320(Obj* self) {
    return (Obj*)((char*)self + 0x24);
}