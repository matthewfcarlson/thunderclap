typedef unsigned int u32;
struct Helper { void Run(u32); };
struct Obj { u32 first; void Target(void*, u32); };
extern void __cdecl FUN_0025b5b0(u32, void*);
extern void __cdecl FUN_0025b320(u32, void*, u32);
void Obj::Target(void* a, u32 b) {
    FUN_0025b5b0(first, a);
    ((Helper*)((char*)a + 0x10))->Run(b);
    FUN_0025b320(first, a, b);
}