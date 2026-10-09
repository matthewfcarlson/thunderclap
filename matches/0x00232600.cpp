class X { char pad[12]; unsigned int flags; public: void f(unsigned int mask, bool enabled); };
void X::f(unsigned int mask, bool enabled) { if (enabled) flags |= mask; else flags &= ~mask; }