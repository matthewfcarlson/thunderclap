struct Vec {
    int x, y, z;
};
struct Obj {
    void doIt(Vec, int, int, int);
};
Obj* get();
extern "C" void _ReadWriteBarrier();
void __cdecl FUN_001b3320(int n, Vec v) {
    if (n >= 0 && n < 13) {
        get()->doIt(v, n, 0, 0);
        _ReadWriteBarrier();
    }
}