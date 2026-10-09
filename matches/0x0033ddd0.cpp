typedef unsigned int u32;
extern void __cdecl f1(u32, int, int);
extern void __cdecl f2(u32, int, const char*);
extern void __cdecl f3(u32, int);
extern void __cdecl f4(u32);
int __cdecl target(u32 p) {
    f1(p, 1, 5);
    f2(p, 0xffffd8ef, "next");
    f3(p, 1);
    f4(p);
    return 3;
}