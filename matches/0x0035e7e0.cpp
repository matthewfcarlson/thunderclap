extern "C" unsigned long long __cdecl FUN_0027b020(const char*);
extern unsigned int gLow;
extern unsigned int gHigh_35e7e0;
void FUN_0035e7e0() {
    unsigned long long r = FUN_0027b020("golfBall_golfBall");
    gLow = (unsigned int)r;
    gHigh_35e7e0 = (unsigned int)(r >> 32);
}
