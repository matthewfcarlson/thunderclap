class Thing { char pad[0x34]; int count; int vals[64]; public: void Add(int value); };
void Thing::Add(int value) { if (count < 0x40) { vals[count] = value; ++count; } }