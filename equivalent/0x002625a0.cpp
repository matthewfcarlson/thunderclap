// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002625a0 @ 0x002625a0
struct Str {
    char data[12];
    void FUN_0023fd20(int capacity);
    bool FUN_00240310(Str* other);
    void FUN_00240060();
};
Str* __cdecl FUN_00262400(Str* src, Str* dst);
bool __cdecl FUN_002625a0(Str* first, Str* second) {
    Str a;
    Str b;
    a.FUN_0023fd20(0x100);
    b.FUN_0023fd20(0x100);
    bool result = FUN_00262400(first, &a)->FUN_00240310(FUN_00262400(second, &b));
    b.FUN_00240060();
    a.FUN_00240060();
    return result;
}
