class Thing { char pad[0x38]; public: float Get(int i); };
float Thing::Get(int i) { if (i >= 0 && i < 8) return *(float*)((char*)this + 0x38 + i * 4); return -1.0f; }