class C { char pad[0x158]; int values[3]; public: void Set(int index, int value); };
void C::Set(int index, int value) { values[index * 3] = value; }