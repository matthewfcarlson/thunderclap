class C { char pad[0x1d0]; public: unsigned char value; unsigned char f(); };
unsigned char C::f() { return value; }