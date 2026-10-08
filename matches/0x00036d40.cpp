class C { char pad[0x2144]; int value; public: void f(int x); };
void C::f(int x) { if (x >= 0 && x < 0xe) value = x; }