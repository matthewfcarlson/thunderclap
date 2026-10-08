class C { char pad[0x630]; public: unsigned int value; unsigned int target(); };
unsigned int C::target() { return value; }