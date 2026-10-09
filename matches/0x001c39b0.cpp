struct X {
    char pad[0x2c];
};
X* __fastcall FUN_001c39b0(X* self) {
    return (X*)((char*)self + 0x2c);
}