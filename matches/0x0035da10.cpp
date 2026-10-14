typedef unsigned int u32;
typedef unsigned long long u64;
extern "C" u64 __cdecl FUN_0027b020(const void*);
extern u32 gA;
extern u32 gB;
void FUN_0035da10() {
    u64 r = FUN_0027b020((const void*)0x400488);
    gA = (u32)r;
    gB = (u32)(r >> 32);
}
