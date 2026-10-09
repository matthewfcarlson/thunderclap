class C { char pad[0x108]; int value; char gap[4]; char flag; public: void Set(int x); };
void C::Set(int x) { value = x; if (x > 0) flag = 1; }