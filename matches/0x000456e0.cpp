class Obj { public: char pad[0x14]; int value; unsigned char Check(); };
unsigned char Obj::Check() { return value == 4; }