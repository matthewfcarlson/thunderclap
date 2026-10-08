class C { public: char pad[0x88]; int value; int target(); };
int C::target() { return value; }