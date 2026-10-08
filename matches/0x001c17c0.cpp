class C { char pad[0xec]; int value; public: void Set(int); };
void C::Set(int x) { value = x; }