typedef unsigned int u32;
extern void __cdecl Build(u32, void*, u32, u32);
extern void __cdecl Finish(u32, void*, const u32*);
void __cdecl Target(u32 a, u32 b, u32 c, const u32* d) {
    char local[20];
    static const u32 fallback = 0x3f;
    if (!d) d = &fallback;
    Build(a, local, b, c);
    Finish(a, local, d);
}