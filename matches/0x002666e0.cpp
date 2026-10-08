class C { char pad[0x14]; public: int value; void f(); };
void C::f() { value = 4; }