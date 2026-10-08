class C { char pad[0x9c]; public: int value; int target(); };
int C::target() { return value; }