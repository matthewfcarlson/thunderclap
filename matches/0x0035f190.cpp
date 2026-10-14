typedef unsigned int u32;
struct Pair {
    u32 lo;
    u32 hi;
};
extern "C" Pair __cdecl FUN_002672f0(u32, u32, u32);
extern u32 g_4ca284;
extern Pair g_4e5b80;
void FUN_0035f190() {
    g_4e5b80 = FUN_002672f0(g_4ca284, 0, 0);
}
