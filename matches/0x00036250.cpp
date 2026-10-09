class C { char pad[0x1b28]; int a; int b; public: void Set(int x); };
void C::Set(int x) { a=x; if (!x) b=x; }