extern "C" unsigned long long __cdecl FUN_0027b020(void*);
extern char g40048c[];
extern unsigned int g4de758;
extern unsigned int g4de75c;
void __cdecl FUN_0035dbb0() {
    unsigned long long v = FUN_0027b020(g40048c);
    *(unsigned int*)&v;
    g4de758 = (unsigned int)v;
    g4de75c = (unsigned int)(v >> 32);
}
