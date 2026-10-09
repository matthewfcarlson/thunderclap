class C { public: int a[11]; void f(int p, int q, int r); };
void C::f(int p, int q, int r) { a[0]=p; a[1]=0; a[2]=0; a[4]=0; a[6]=0; a[8]=0; a[9]=0; a[5]=q; a[10]=r; }