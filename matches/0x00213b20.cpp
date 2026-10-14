typedef unsigned int u32_213b20;
extern void __cdecl Build(u32_213b20, void*, u32_213b20, u32_213b20);
extern void __cdecl Finish(u32_213b20, void*, const u32_213b20*);
void __cdecl Target(u32_213b20 a, u32_213b20 b, u32_213b20 c, const u32_213b20* d) {
    char local[20];
    static const u32_213b20 fallback = 0x3f;
    if (!d)
        d = &fallback;
    Build(a, local, b, c);
    Finish(a, local, d);
}