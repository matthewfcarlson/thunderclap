class C { char pad[0x254]; public: int value; int target(); };
int C::target() { return value; }