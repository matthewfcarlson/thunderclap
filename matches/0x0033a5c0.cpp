typedef unsigned int u32;
extern void f339dc0(void*, int);
extern u32 f339f70(void*, int);
extern void f339d70(void*, int, int);
extern int f212f40(void*, int);
extern int f213e50(void*, int, u32);
extern void f2133d0(void*, int);
extern void f212e20(void*, int);
int target(void* self, int unused) {
    u32 edi;
    int r;
    f339dc0(self, 3);
    edi = f339f70(self, 2);
    f339d70(self, 1, 6);
    r = f212f40(self, 1);
    if (r != 0) return 0;
    r = f213e50(self, 1, edi);
    if (r == 0) return 0;
    f2133d0(self, r);
    f212e20(self, -1);
    return 1;
}