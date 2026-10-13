struct Obj {
    char pad[0x50];
    Obj* FUN_0015ac80();
};
Obj* Obj::FUN_0015ac80() {
    return (Obj*)((char*)this + 0x50);
}
