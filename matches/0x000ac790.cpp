class Target { char pad[0x18]; public: int value; unsigned char flag; void Set(int x); };
void Target::Set(int x) { value = x; flag = 1; }