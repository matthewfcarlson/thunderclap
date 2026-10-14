typedef unsigned int U_33a560;
extern U_33a560 __cdecl F339f70(U_33a560, int);
extern void __cdecl F339d70(U_33a560, int, int);
extern U_33a560 __cdecl F212f40(U_33a560, int);
extern U_33a560 __cdecl F213dd0(U_33a560, int, U_33a560);
extern void __cdecl F2133d0(U_33a560, U_33a560);
extern void __cdecl F212e20(U_33a560, int);
int __cdecl target(U_33a560 p) {
    U_33a560 v = F339f70(p, 2);
    F339d70(p, 1, 6);
    if (F212f40(p, 1) != 0)
        return 0;
    U_33a560 r = F213dd0(p, 1, v);
    if (r == 0)
        return 0;
    F2133d0(p, r);
    F212e20(p, -2);
    return 2;
}