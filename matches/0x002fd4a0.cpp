class C { public: char pad[0x70]; int *p; void f(); };
void C::f() { int *p = this->p; if (p) { p[0x44/4] = 0; p[0x40/4] = 0; } }