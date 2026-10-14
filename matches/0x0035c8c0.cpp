extern "C" unsigned long long FUN_0027b020(const char*);
extern unsigned int gA;
extern unsigned int gB;
void FUN_0035c8c0() {
    unsigned long long r = FUN_0027b020("devil_hulk");
    gA = (unsigned int)r;
    gB = (unsigned int)(r >> 32);
}
