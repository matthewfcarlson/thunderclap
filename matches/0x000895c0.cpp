class C { char pad[0xab8]; int value; public: void Set(int); };
void C::Set(int x) { value = x; if (x < 0 || 2 < x) value = 1; }