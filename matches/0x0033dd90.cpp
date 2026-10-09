typedef unsigned int u32;
extern void __cdecl f339d70(u32, int, int);
extern void __cdecl f212d80(u32, int);
extern int __cdecl f213c50(u32, int);
extern void __cdecl f213320(u32);
int __cdecl target(u32 p) {
    f339d70(p, 1, 5);
    f212d80(p, 2);
    if (f213c50(p, 1)) return 2;
    f213320(p);
    return 1;
}