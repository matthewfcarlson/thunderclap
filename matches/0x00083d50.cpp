class C { char pad[0x20]; public: int value; void set(int x); };
void C::set(int x) { value = x; }