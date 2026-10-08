struct C { char pad[0xabc]; unsigned char value; void Set(unsigned char x); };
void C::Set(unsigned char x) { value = x; }