typedef unsigned int u32_33dd90;
extern void __cdecl f339d70(u32_33dd90, int, int);
extern void __cdecl f212d80(u32_33dd90, int);
extern int __cdecl f213c50(u32_33dd90, int);
extern void __cdecl f213320(u32_33dd90);
int __cdecl target(u32_33dd90 p) {
    f339d70(p, 1, 5);
    f212d80(p, 2);
    if (f213c50(p, 1))
        return 2;
    f213320(p);
    return 1;
}