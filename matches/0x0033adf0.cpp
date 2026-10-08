typedef unsigned int U;
extern void __cdecl FUN_00339d70(void*, int, int);
extern U __cdecl FUN_003392c0(void*, int);
extern void __cdecl FUN_00213360(void*, U);
int __cdecl target(void* p) {
    FUN_00339d70(p, 1, 5);
    U x = FUN_003392c0(p, 1);
    FUN_00213360(p, x);
    return 1;
}