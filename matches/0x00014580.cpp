class A { public: char pad[0x20]; struct B *p; float f(); };
struct B { char pad[0x2c]; float value; };
float A::f() { return p->value; }