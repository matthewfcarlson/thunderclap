typedef unsigned int u32_33ae20;
extern void __cdecl f1(u32_33ae20, int, int);
extern u32_33ae20 __cdecl f2(u32_33ae20, int);
extern void __cdecl f3(u32_33ae20, int, u32_33ae20);
int __cdecl target(u32_33ae20 a) {
    f1(a, 1, 5);
    u32_33ae20 v = f2(a, 2);
    f3(a, 1, v);
    return 0;
}