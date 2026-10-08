class C { public: char pad[0x820]; unsigned char a; unsigned char b; void f(); };
void C::f() { a = 0; b = 0; }