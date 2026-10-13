struct Obj {
    char pad[0x18];
    void* m18;
};
void* __fastcall FUN_0012b2c0(Obj* self) {
    return (char*)self + 0x18;
}
