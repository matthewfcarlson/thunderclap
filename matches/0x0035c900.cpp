typedef unsigned __int64 U64;
extern "C" U64 __cdecl FUN_0027b020(const char*);
extern int gA;
extern int gB;
void FUN_0035c900() {
    U64 r = FUN_0027b020((const char*)0x3f3fd8);
    gA = (int)r;
    gB = (int)(r >> 32);
}
