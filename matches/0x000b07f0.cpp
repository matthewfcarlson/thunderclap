class Target { char pad[0x4a0]; public: int value; unsigned char Set(int x); };
unsigned char Target::Set(int x) { value = x; return 1; }