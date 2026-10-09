class C { public: char pad[0xbf8]; int values[100]; int Get(int index); };
int C::Get(int index) { if (index >= 100) return -1; return values[index]; }