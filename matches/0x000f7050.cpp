class C { char pad[0x114]; int field; public: void Set(int value); };
void C::Set(int value) { field = value; }