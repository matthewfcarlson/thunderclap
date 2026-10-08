class C { public: char pad[12]; unsigned int value; unsigned int get(); };
unsigned int C::get() { return value; }