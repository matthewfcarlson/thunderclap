class C { char pad[0xcc]; unsigned char flag; char pad2[0xf]; int a; int b; int c; public: void f(int* p); };
void C::f(int* p) { a=p[0]; b=p[1]; c=p[2]; flag=0; }