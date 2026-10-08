class C { public: char pad[0xdc]; int value; void Set(int x); };
void C::Set(int x) { value = x; }