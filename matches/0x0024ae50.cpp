extern "C" char DAT_004e5fa8[];
struct Obj {
    int x;
    void Helper();
    Obj* Bar(unsigned char flag);
};
void __cdecl FUN_00247550(void*, Obj*);
Obj* Obj::Bar(unsigned char flag) {
    Helper();
    if (flag & 1)
        FUN_00247550((void*)((int)DAT_004e5fa8), this);
    return this;
}
