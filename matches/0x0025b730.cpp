typedef unsigned int u32_25b730;
struct Helper_25b730 {
    void Run(u32_25b730);
};
struct Obj_25b730 {
    u32_25b730 first;
    void Target(void*, u32_25b730);
};
extern void __cdecl FUN_0025b5b0(u32_25b730, void*);
extern void __cdecl FUN_0025b320(u32_25b730, void*, u32_25b730);
void Obj_25b730::Target(void* a, u32_25b730 b) {
    FUN_0025b5b0(first, a);
    ((Helper_25b730*)((char*)a + 0x10))->Run(b);
    FUN_0025b320(first, a, b);
}