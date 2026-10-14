extern "C" unsigned long long FUN_0027b020(const char*);
extern unsigned int gA_35c8c0;
extern unsigned int gB_35c8c0;
void FUN_0035c8c0() {
    unsigned long long r = FUN_0027b020("devil_hulk");
    gA_35c8c0 = (unsigned int)r;
    gB_35c8c0 = (unsigned int)(r >> 32);
}
