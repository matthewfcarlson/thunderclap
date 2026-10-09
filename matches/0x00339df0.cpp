extern int __cdecl F213190(void*, void*);
extern int __cdecl F212f20(void*, int);
extern int __cdecl F212f00(void*, void*);
extern int __cdecl F213470(void*, const char*, int, int);
extern void __cdecl F339c30(void*, void*, int);
extern int __cdecl F2131f0(void*, void*);
int __cdecl Target(void* a, void* b, int* out) {
    int r = F213190(a, b);
    if (!r) {
        int x = F212f20(a, 4);
        int y = F212f20(a, F212f00(a, b));
        F339c30(a, b, F213470(a, "%s expected, got %s", x, y));
    }
    if (out)
        *out = F2131f0(a, b);
    return r;
}