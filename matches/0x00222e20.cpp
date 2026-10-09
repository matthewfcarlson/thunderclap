class C { public: char pad[0x68]; unsigned count; unsigned char rest[1]; unsigned f(unsigned i); };
unsigned C::f(unsigned i) { if (i < count) return *(unsigned *)(rest + i * 0x28); return 0; }