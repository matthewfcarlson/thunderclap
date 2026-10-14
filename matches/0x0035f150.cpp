extern "C" unsigned long long __cdecl FUN_002672f0(int, int, int);
extern int gGlobal;
int gLow;
int gHigh;
void __cdecl FUN_0035f150() {
    unsigned long long v = FUN_002672f0(gGlobal, 0, 0);
    gLow = (int)v;
    gHigh = (int)(v >> 32);
}
