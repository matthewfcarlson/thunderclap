extern "C" void __cdecl FUN_00339df0(void*, int, int*);
extern "C" void __cdecl FUN_00213360(void*, int);
extern "C" int __cdecl FUN_0033bd00(void* p) {
    int n;
    FUN_00339df0(p, 1, &n);
    FUN_00213360(p, n);
    return 1;
}