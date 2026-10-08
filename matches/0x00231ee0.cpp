class C { char p[4]; public: int a; char q[0x18]; int b; unsigned char F(); };
unsigned char C::F() { if (a) return 1; return b != 0; }