struct Obj {
    char pad[0x430];
};
void* __fastcall FUN_00044400(Obj* self) {
    return (char*)self + 0x430;
}