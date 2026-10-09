typedef unsigned int U;
struct S { U a[5]; };
void __cdecl f(U p1, S* p2, U p3, U p4) { p2->a[4]=p1; p2->a[2]=p3; p2->a[3]=p4; p2->a[0]=0; p2->a[1]=0; }