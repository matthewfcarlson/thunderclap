extern "C" unsigned long long FUN_0027b020(const char*);
extern unsigned int gHash_35d1e0;
extern unsigned int gHash2;
void FUN_0035d1e0() {
    unsigned long long h = FUN_0027b020("golfBall_golfBall");
    gHash_35d1e0 = (unsigned int)h;
    gHash2 = (unsigned int)(h >> 32);
}