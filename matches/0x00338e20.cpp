typedef unsigned int U_338e20;
extern void __cdecl F1(U_338e20, int);
extern void __cdecl F2(U_338e20, U_338e20, U_338e20*);
extern void __cdecl F3(U_338e20, int);
extern int __cdecl F4(U_338e20);
int __cdecl target(U_338e20 a, U_338e20 b, U_338e20 c) {
    F1(a, 1);
    F2(a, b, &c);
    F3(a, 2);
    return F4(a);
}
