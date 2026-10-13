struct Obj {
    char pad[0x58];
    int member;
};
int* __fastcall FUN_0015ac90(Obj* self) {
    return (int*)((char*)self + 0x58);
}
