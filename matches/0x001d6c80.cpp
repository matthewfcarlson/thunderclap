class C { char pad[0x254]; int value; public: void Set(int x); };
void C::Set(int x) { value = x; }