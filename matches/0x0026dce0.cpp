extern "C" void _ReadWriteBarrier(void);
void __cdecl helper(int, int, int, int, int);
void __cdecl FUN_0026dce0(int a, int b, int c, int d, int e) {
    helper(a, b, c, d, e);
    _ReadWriteBarrier();
}