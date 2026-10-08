class Target { char pad[0x20]; public: unsigned char field; void Reset(); };
void Target::Reset() { field = 0; }