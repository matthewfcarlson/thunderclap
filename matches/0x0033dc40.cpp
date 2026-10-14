typedef unsigned int U_33dc40;
extern void __cdecl f1(U_33dc40, U_33dc40, U_33dc40);
extern void __cdecl f2(U_33dc40, U_33dc40);
extern void __cdecl f3(U_33dc40, U_33dc40);
int __cdecl target(U_33dc40 a) {
    f1(a, 1, 5);
    f2(a, 2);
    f2(a, 3);
    f3(a, 1);
    return 1;
}