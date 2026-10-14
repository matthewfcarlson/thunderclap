extern "C" unsigned long long __cdecl Define(const char*);
extern unsigned int gFirst;
extern unsigned int gSecond;

void __cdecl FUN_0035d760() {
    unsigned long long r = Define("$MACRO_DEFINE");
    gFirst = (unsigned int)r;
    gSecond = (unsigned int)(r >> 32);
}
