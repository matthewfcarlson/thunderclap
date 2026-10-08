class A { public: char pad[4]; unsigned char flag; void f(); };
void A::f() { if (!flag) flag = 1; }