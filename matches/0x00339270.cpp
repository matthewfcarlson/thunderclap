typedef unsigned int U;
extern int FUN_00212d70(void*);
extern void FUN_003391f0();
extern void FUN_00212ed0(void*, int);
extern void FUN_00213360(void*, U);
extern void FUN_00213800(void*, int);
extern void FUN_00212d80(void*, int);
void FUN_00339270(void* a, int b, U c) {
    if (b <= 0 && b > -10000)
        b = b + 1 + FUN_00212d70(a);
    FUN_003391f0();
    FUN_00212ed0(a, b);
    FUN_00213360(a, c);
    FUN_00213800(a, -3);
    FUN_00212d80(a, -2);
}