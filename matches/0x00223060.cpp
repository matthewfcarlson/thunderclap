class A { public: int f(); };
class B { public: void g(int); };
class C { public: char pad[0x10]; A a; void f(); };
void C::f() { int x = a.f(); ((B*)*(void**)((char*)this + 0x64))->g(x); }