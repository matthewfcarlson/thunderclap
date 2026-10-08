class A { public: void f(int,int); };
class B { public: void f(int,int); };
class V { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void f(int,int); };
class C { public: char p[12]; A* a; char q[4]; B* b; V* c; void f(int,int); };
void C::f(int x,int y) { a->f(x,y); b->f(x,y); c->f(x,y); }