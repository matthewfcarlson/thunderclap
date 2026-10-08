class Target { char pad[0x1cf4]; public: unsigned char value; void Set(unsigned char x); };
void Target::Set(unsigned char x) { value = x; }