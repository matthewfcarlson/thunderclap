class C { char pad[0x68]; public: void f(int); void next(void*,int); };
extern void __cdecl helper(void*, void*, int, int);
struct S { int a,b; };
void C::f(int p) { S s; s.a=8; s.b=p; helper(pad+0x68,&s,8,0); next(&s,8); }