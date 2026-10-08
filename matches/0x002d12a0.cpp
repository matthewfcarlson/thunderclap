class C { char pad0[0x10]; int a; char pad1[0x0c]; int b; public: void Set(int x, int y); };
void C::Set(int x, int y) { a=x; b=y; }