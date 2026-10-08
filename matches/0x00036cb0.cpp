class X { public: char pad[0x1e04]; unsigned int values[16]; unsigned int Get(unsigned int i); };
unsigned int X::Get(unsigned int i) { if (i >= 16) return 0; return values[i]; }