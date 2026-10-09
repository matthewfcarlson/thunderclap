float gZero = 0.0f;
extern "C" void F135a0(int, int, int);
extern "C" int F12f00(int, int);
extern "C" void F12d80(int, int);
extern "C" float F130e0(int, int);
float __stdcall FUN_001d1010(int a, int b) {
    if (a == 0)
        return gZero;
    F135a0(b, -10001, a);
    int r = F12f00(b, -1);
    if (r != 3) {
        F12d80(b, -2);
        return gZero;
    }
    float x = F130e0(b, -1);
    F12d80(b, -2);
    return x;
}