typedef unsigned int U;
extern void __cdecl f339(U, int);
extern U __cdecl f2130(U, int, int);
extern void __cdecl f2135(U, U);
int __cdecl target(U p) {
 f339(p,1);
 f339(p,2);
 U x=f2130(p,1,2);
 f2135(p,x);
 return 1;
}