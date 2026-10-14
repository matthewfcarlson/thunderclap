extern "C" unsigned __int64 FUN_0027b020(unsigned int);
extern unsigned int gHi_35d420;
extern unsigned int gLo;
void FUN_0035d420() {
    unsigned __int64 v = FUN_0027b020(0x400488);
    gHi_35d420 = (unsigned int)v;
    gLo = (unsigned int)(v >> 32);
}
