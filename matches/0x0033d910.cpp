typedef unsigned int uint;
extern void __cdecl f1(void*, int);
extern int __cdecl f2(void*, int);
extern void __cdecl f3(void*);
extern void __cdecl f4(void*, int, const char*);
int __cdecl target(void* p) {
    f1(p, 1);
    if (f2(p, 1) == 0) {
        f3(p);
        return 1;
    }
    f4(p, 1, "__metatable");
    return 1;
}