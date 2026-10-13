struct S {
    char pad[0x44];
};
S* __fastcall FUN_00012be0(S* self) {
    return (S*)((char*)self + 0x44);
}
