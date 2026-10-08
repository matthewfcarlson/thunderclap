class Target { public: char pad[0x354c]; int values[1]; int Get(int index); };
int Target::Get(int index) { return values[index]; }