typedef unsigned int U;
extern void __cdecl f339dc0(U, int);
extern U __cdecl f212f00(U, int);
extern U __cdecl f212f20(U, U);
extern void __cdecl f2133d0(U, U);
U __cdecl target(U a) {
    f339dc0(a, 1);
    U x = f212f00(a, 1);
    x = f212f20(a, x);
    f2133d0(a, x);
    return 1;
}