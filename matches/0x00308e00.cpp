class C { char pad[0x40]; public: int a; int b; void f(); };
void C::f() { b = 0; a = 0; }