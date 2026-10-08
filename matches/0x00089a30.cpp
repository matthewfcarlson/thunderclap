class Target { char pad[0xabd]; public: void Set(unsigned char value); };
void Target::Set(unsigned char value) { *((unsigned char*)this + 0xabd) = value; }