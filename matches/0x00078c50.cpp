class C { public: char pad[0x382c]; int value; void Set(int x); };
void C::Set(int x) { value = x; }