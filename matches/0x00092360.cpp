class Target { char pad[0xb0]; unsigned char value; public: void Set(unsigned char x); };
void Target::Set(unsigned char x) { value = x; }