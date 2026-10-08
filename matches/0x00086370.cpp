class A { char pad[0x48]; public: int x; int f(); };
int A::f() { return x; }