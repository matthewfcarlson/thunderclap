class Target { char pad[0x111]; unsigned char value; public: void Set(unsigned char x); };
void Target::Set(unsigned char x) { value = x; }
