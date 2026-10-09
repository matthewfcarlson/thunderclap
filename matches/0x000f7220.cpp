class C { public: char pad0[0x0c]; int* items; int max; int Get(int index); };
int C::Get(int index) { if (index < 0 || index > max) return 0; return items[index]; }