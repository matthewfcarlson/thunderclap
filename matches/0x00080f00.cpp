class C { char pad[0xc0]; int field; public: void Set(int x); };
void C::Set(int x) { field = x; }