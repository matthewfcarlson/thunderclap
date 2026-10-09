typedef unsigned int U;
extern U __cdecl F339f70(U, int);
extern void __cdecl F339d70(U, int, int);
extern U __cdecl F212f40(U, int);
extern U __cdecl F213dd0(U, int, U);
extern void __cdecl F2133d0(U, U);
extern void __cdecl F212e20(U, int);
int __cdecl target(U p) {
    U v = F339f70(p, 2);
    F339d70(p, 1, 6);
    if (F212f40(p, 1) != 0) return 0;
    U r = F213dd0(p, 1, v);
    if (r == 0) return 0;
    F2133d0(p, r);
    F212e20(p, -2);
    return 2;
}