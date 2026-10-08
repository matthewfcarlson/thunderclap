struct X { void f(); };
struct C { char pad[0x5c]; X* member; void target(); };
void C::target() { member->f(); }