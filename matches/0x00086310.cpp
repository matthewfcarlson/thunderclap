class C { char pad[0x38]; public: unsigned int value; unsigned int f(); };
unsigned int C::f() { return value; }