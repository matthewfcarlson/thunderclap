class Target { char pad[0x10]; int value; public: int Get(int index); };
int Target::Get(int index) { return value + index * 0x24; }