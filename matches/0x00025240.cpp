class C { public: char pad[0x340]; float value; void f(float); };
void C::f(float x) { if (x > value) value = x; }