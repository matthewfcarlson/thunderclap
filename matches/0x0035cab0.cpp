extern "C" unsigned long long __cdecl FUN_0027b020(const char*);
extern "C" unsigned int g4dcec8;
extern "C" unsigned int g4dcec8_1;
void __cdecl FUN_0035cab0() {
    unsigned long long r = FUN_0027b020("throwing");
    g4dcec8 = (unsigned int)r;
    g4dcec8_1 = (unsigned int)(r >> 32);
}