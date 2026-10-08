class C { public: char pad[0xb0]; unsigned char value; unsigned char get(); };
unsigned char C::get() { return value; }