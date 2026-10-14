typedef unsigned int u32;
typedef unsigned long long u64_35da10;
extern "C" u64_35da10 __cdecl FUN_0027b020(const void*);
extern u32 gA_35da10;
extern u32 gB_35da10;
void FUN_0035da10() {
    u64_35da10 r = FUN_0027b020((const void*)0x400488);
    gA_35da10 = (u32)r;
    gB_35da10 = (u32)(r >> 32);
}
