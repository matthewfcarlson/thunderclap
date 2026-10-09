class B { public: void g(void*, int, int, int); };
class A { public: char pad[0x284]; B* member; void f(void*); };
void A::f(void* param) { member->g(param, 3, 4, 1); }