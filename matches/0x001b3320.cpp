struct Vec {
    int x, y, z;
};
struct Obj {
    void doIt();
};
Obj* __stdcall get(Vec, int, int, int);
extern "C" void _ReadWriteBarrier();
void __cdecl FUN_001b3320(int n, Vec v) {
    if (n >= 0 && n < 13) {
        Obj* p = get(v, n, 0, 0);
        p->doIt();
        _ReadWriteBarrier();
    }
}