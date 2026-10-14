struct Obj {
    char pad[0x354];
    int field;
};
Obj* __cdecl FUN_000678d0();
void __cdecl FUN_00024b80() {
    FUN_000678d0()->field = 0;
}
