class C { char pad[0x34]; public: int a,b,c; void f(int*,int*,int*); };
void C::f(int* x,int* y,int* z) { *x=a; *y=b; *z=c; }