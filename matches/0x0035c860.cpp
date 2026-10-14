extern "C" unsigned long long __cdecl FUN_0027b020(const char*);
extern unsigned int g004dc098;
extern unsigned int g004dc09c;
void FUN_0035c860() {
    unsigned long long r = FUN_0027b020("bradley");
    g004dc098 = (unsigned int)r;
    g004dc09c = (unsigned int)(r >> 32);
}
