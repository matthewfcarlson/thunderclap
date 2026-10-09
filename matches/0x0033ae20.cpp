typedef unsigned int u32;
extern void __cdecl f1(u32, int, int);
extern u32 __cdecl f2(u32, int);
extern void __cdecl f3(u32, int, u32);
int __cdecl target(u32 a) {
    f1(a, 1, 5);
    u32 v = f2(a, 2);
    f3(a, 1, v);
    return 0;
}