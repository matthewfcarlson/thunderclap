class C { public: char pad[0x18]; int* p; int Get(int index); };
int C::Get(int index) { return p[index]; }