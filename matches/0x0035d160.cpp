typedef unsigned int uint32;
typedef unsigned long long uint64;
extern "C" uint64 __cdecl FUN_0027b020(const char*);
extern uint32 gA_35d160;
extern uint32 gB_35d160;
void __cdecl FUN_0035d160() {
    uint64 r = FUN_0027b020((const char*)0x400488);
    gA_35d160 = (uint32)r;
    gB_35d160 = (uint32)(r >> 32);
}
