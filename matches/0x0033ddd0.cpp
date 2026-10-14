typedef unsigned int u32_33ddd0;
extern void __cdecl f1(u32_33ddd0, int, int);
extern void __cdecl f2(u32_33ddd0, int, const char*);
extern void __cdecl f3(u32_33ddd0, int);
extern void __cdecl f4(u32_33ddd0);
int __cdecl target(u32_33ddd0 p) {
    f1(p, 1, 5);
    f2(p, 0xffffd8ef, "next");
    f3(p, 1);
    f4(p);
    return 3;
}