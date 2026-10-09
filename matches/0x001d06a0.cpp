extern int __cdecl FUN_00213260(void*, int);
extern void __cdecl FUN_002136d0(void*, int);
extern void __cdecl FUN_00212ed0(void*, int);
extern void __cdecl FUN_00213600(void*, int);
extern int __cdecl FUN_00212f00(void*, int);
extern int __cdecl FUN_00212f70(void*, int);
extern void __cdecl FUN_002130e0(void*, int);
extern int __cdecl FUN_0034483c();
extern void __cdecl FUN_00213340(void*, int);
extern void __cdecl FUN_002133d0(void*, const char*);
extern void __cdecl FUN_00213c40(void*);
int __cdecl target(void* p) {
    int* a;
    int x;
    a = (int*)FUN_00213260(p, 1);
    FUN_002136d0(p, 1);
    FUN_00212ed0(p, 2);
    FUN_00213600(p, -2);
    x = FUN_00212f00(p, -1);
    if (x != 6) {
        if (FUN_00212f70(p, -1) != 0) {
            FUN_002130e0(p, -1);
            x = FUN_0034483c();
            FUN_00213340(p, a[x]);
            return 1;
        }
        FUN_002133d0(p, "invalid index");
        FUN_00213c40(p);
        return 0;
    }
    return 1;
}