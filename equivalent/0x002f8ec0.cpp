// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002f8ec0 @ 0x002f8ec0
struct Obj {
    void FUN_002f8d90(int, int, int, int, int, int);
    Obj* FUN_002f8ec0(int, int, int, int, int, int);
};
Obj* Obj::FUN_002f8ec0(int a, int b, int c, int d, int e, int f) {
    FUN_002f8d90(a, b, c, d, e, f);
    return this;
}
