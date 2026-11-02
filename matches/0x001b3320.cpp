struct Vec {
    int x, y, z;
};
struct Obj {
    void doIt(Vec, int, int, int);
};
extern "C" void * __cdecl FUN_001b6580(void);
extern "C" void _ReadWriteBarrier();
void __cdecl FUN_001b3320(int n, Vec v) {
    if (n >= 0 && n < 13) {
        ((Obj *)FUN_001b6580())->doIt(v, n, 0, 0);
        _ReadWriteBarrier();
    }
}