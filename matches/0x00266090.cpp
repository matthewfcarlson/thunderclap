class A { public: char pad[12]; int* p; int f(); };
int A::f() { return p[1]; }