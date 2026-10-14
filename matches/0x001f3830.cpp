struct Helper_1f3830 {
    void Run();
};
struct Thing_1f3830 {
    char pad[8];
    Helper_1f3830 sub;
    Thing_1f3830* F(unsigned char);
};
void __cdecl thunk_FUN_00267090(Thing_1f3830*);
Thing_1f3830* Thing_1f3830::F(unsigned char flags) {
    sub.Run();
    ((Helper_1f3830*)this)->Run();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}