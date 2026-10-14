typedef unsigned __int64 U64_35d3c0;
extern "C" U64_35d3c0 __cdecl FUN_0027b020(const char* s);
extern int gMac1;
extern int gMac2;

void __cdecl FUN_0035d3c0() {
    U64_35d3c0 r = FUN_0027b020("$MACRO_DEFINE");
    gMac1 = (int)r;
    gMac2 = (int)(r >> 32);
}
