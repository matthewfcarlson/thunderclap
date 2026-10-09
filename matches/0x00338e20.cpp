typedef unsigned int U;
extern void __cdecl F1(U,int);
extern void __cdecl F2(U,U,U*);
extern void __cdecl F3(U,int);
extern void __cdecl F4(U);
void __cdecl target(U a, U b, U c){ F1(a,1); F2(a,b,&c); F3(a,2); F4(a); }
