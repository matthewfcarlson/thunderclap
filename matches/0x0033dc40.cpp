typedef unsigned int U;
extern void __cdecl f1(U, U, U);
extern void __cdecl f2(U, U);
extern void __cdecl f3(U, U);
int __cdecl target(U a) {
    f1(a, 1, 5);
    f2(a, 2);
    f2(a, 3);
    f3(a, 1);
    return 1;
}