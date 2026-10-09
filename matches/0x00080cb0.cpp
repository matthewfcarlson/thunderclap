class C { char pad[0x10]; public: int value; char pad2[0x14]; unsigned int flags; void F(int); };
void C::F(int x) { if (x >= 0 && x < 16) { value = x; flags |= 2; } }