class C { char pad[0x1e8]; public: unsigned value; unsigned get(); };
unsigned C::get() { return value; }