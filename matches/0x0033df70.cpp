struct Data {
    int a;
    int b;
};
extern int __cdecl f1(void*, int, int);
extern int __cdecl f2(void*, int, int);
extern int __cdecl f3(void*, int, int);
extern int __cdecl f4(void*, int);
extern int __cdecl f5(void*, int);
extern int __cdecl f6(void*, int);
extern int __cdecl f7(void*, int);
extern int __cdecl f8(void*, int);
extern int __cdecl f10(void*, const char*);
int __cdecl FUN_0033df70(void* a, Data* d, int* out) {
    f1(a, d->b, 0xffffd8f0);
    f2(a, 0xffffd8f0, d->a);
    f3(a, 0, 1);
    int x = f4(a, -1);
    if (!x) {
        *out = x;
        return 0;
    }
    if (f5(a, -1)) {
        int b = f6(a, -1);
        *out = f7(a, -1);
        d->b = f8(a, 0xffffd8f0);
        return b;
    }
    f10(a, "reader function must return a string");
    return 0;
}