class C { public: char pad[0xfc]; int value; int target(); };
int C::target() { return value == 2 || value == 3; }