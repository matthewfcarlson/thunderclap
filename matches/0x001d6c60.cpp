class C { char pad[0x250]; int value; public: void set(int x); };
void C::set(int x) { value = x; }