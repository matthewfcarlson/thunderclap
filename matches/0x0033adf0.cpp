typedef unsigned int U_33adf0;
extern void __cdecl FUN_00339d70(void*, int, int);
extern U_33adf0 __cdecl FUN_003392c0(void*, int);
extern void __cdecl FUN_00213360(void*, U_33adf0);
int __cdecl target(void* p) {
    FUN_00339d70(p, 1, 5);
    U_33adf0 x = FUN_003392c0(p, 1);
    FUN_00213360(p, x);
    return 1;
}