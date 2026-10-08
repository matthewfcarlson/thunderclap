class C { public: char pad[0x49c]; int value; void Set(int); };
void C::Set(int x) { value = x; }