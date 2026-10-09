typedef unsigned int u32;
extern void __cdecl f339d70(void*, int, int);
extern int __cdecl f3392c0(void*, int);
extern void __cdecl f338fe0(void*, int, const float*);
extern int __cdecl f212f00(void*, int);
extern void __cdecl f212d80(void*, int);
extern void __cdecl f33b110(void*, int, int);
extern const float gZero;
int __cdecl target(void* p) {
    f339d70(p, 1, 5);
    int v = f3392c0(p, 1);
    f338fe0(p, 0x28, &gZero);
    int n = f212f00(p, 2);
    if (n > 0)
        f339d70(p, 2, 6);
    f212d80(p, 2);
    f33b110(p, 1, v);
    return 0;
}