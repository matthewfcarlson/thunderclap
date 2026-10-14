typedef unsigned int U_33dd60;
extern void __cdecl f339dc0(U_33dd60, int);
extern U_33dd60 __cdecl f212f00(U_33dd60, int);
extern U_33dd60 __cdecl f212f20(U_33dd60, U_33dd60);
extern void __cdecl f2133d0(U_33dd60, U_33dd60);
U_33dd60 __cdecl target(U_33dd60 a) {
    f339dc0(a, 1);
    U_33dd60 x = f212f00(a, 1);
    x = f212f20(a, x);
    f2133d0(a, x);
    return 1;
}