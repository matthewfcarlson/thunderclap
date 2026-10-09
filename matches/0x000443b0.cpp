struct A {
    char pad[0x3f0];
};
A* __fastcall FUN_000443b0(A* self) {
    return (A*)((char*)self + 0x3f0);
}