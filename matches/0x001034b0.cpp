class Obj { public: char pad[0x5c]; char* p; void FUN_001034b0(unsigned char); };
void Obj::FUN_001034b0(unsigned char value) { if (p) p[0x91] = value; }