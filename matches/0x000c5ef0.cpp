extern "C" bool __cdecl Test(int, int, int, int, int, int, int);

extern "C" bool __cdecl FUN_000c5ef0(int a, int b, int c, int d, int e, int f) {
    int i = 0;
    do {
        if (Test(a, i, b, c, d, e, f))
            return true;
        ++i;
    } while (i < 1);
    return false;
}