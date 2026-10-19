extern "C" char hulk_at_004dd940[];
extern "C" double __cdecl cos(double);
extern "C" void __cdecl FUN_0035d200() {
    double r = cos(0.017453293005625408);
    *(volatile float*)((int)hulk_at_004dd940) = 1.0f - (float)r;
}
