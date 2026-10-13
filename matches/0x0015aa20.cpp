struct Obj {
    char pad[0x58];
    int data;
};
Obj* __fastcall FUN_0015aa20(Obj* self) {
    return (Obj*)((char*)self + 0x58);
}
