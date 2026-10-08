class C { char pad[0xb5]; public: unsigned char value; unsigned char f(); };
unsigned char C::f() { return value; }