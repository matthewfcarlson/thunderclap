class C { char pad[0x30]; public: int a; int b; int c; void f(); };
void C::f() { c = 0; b = 0; a = 0; }