class Thing { public: char pad[0x154]; int values[3]; void set(int index, int value); };
void Thing::set(int index, int value) { values[index * 3] = value; }