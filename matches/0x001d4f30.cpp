class C { public: char pad[0x98]; int value; int get(); };
int C::get() { return value; }