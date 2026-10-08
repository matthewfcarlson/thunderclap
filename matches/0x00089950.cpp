class C { public: char pad[0x10c]; unsigned int value; unsigned int get(); };
unsigned int C::get() { return value; }