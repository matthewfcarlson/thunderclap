typedef unsigned int U_33dbe0;
extern void __cdecl f339(U_33dbe0, int);
extern U_33dbe0 __cdecl f2130(U_33dbe0, int, int);
extern void __cdecl f2135(U_33dbe0, U_33dbe0);
int __cdecl target(U_33dbe0 p) {
    f339(p, 1);
    f339(p, 2);
    U_33dbe0 x = f2130(p, 1, 2);
    f2135(p, x);
    return 1;
}