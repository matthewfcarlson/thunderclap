class A { char pad[0x434]; public: unsigned char value; unsigned char f(); };
unsigned char A::f() { return value; }