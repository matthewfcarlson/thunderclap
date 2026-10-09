class X { public: char pad[0x22ac]; int value; void f(bool b); };
void X::f(bool b) { if (b) ++value; else --value; }