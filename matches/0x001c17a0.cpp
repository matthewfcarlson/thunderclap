class Obj { char pad[0xe4]; public: unsigned a; unsigned b; void Set(unsigned x, unsigned y); };
void Obj::Set(unsigned x, unsigned y) { a = x; b = y; }