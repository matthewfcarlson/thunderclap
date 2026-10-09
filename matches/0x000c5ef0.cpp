extern "C" bool __cdecl Test(int, int, int, int, int, int, int);

bool __cdecl Target(int a, int b, int c, int d, int e, int f) {
    int i = 0;
    do {
        if (Test(a, i, b, c, d, e, f))
            return true;
        ++i;
    } while (i < 1);
    return false;
}