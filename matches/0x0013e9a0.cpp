struct SubObj {
    char pad[0x40];
    char* p40;
};
struct Obj {
    char pad[0x40];
    char* p40;
};
Obj* __fastcall FUN_0013e9a0(Obj* self) {
    return (Obj*)((char*)self + 0x40);
}