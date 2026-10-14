extern "C" unsigned long long __cdecl Define(const char*);
extern unsigned int gFirst_35d760;
extern unsigned int gSecond_35d760;

void __cdecl FUN_0035d760() {
    unsigned long long r = Define("$MACRO_DEFINE");
    gFirst_35d760 = (unsigned int)r;
    gSecond_35d760 = (unsigned int)(r >> 32);
}
