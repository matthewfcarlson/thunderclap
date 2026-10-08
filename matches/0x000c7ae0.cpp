class C { char pad[0x228]; int value; public: void Set(int x); };
void C::Set(int x) { value = x; }