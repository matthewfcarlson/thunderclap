class C { char pad[0xc10]; public: void* f(int x); };
void* C::f(int x) { if (x >= 0 && x < 9) return (void*)((char*)this + 0xc10 + x * 0x20); return 0; }