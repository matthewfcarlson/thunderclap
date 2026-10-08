class C { char pad[0x10]; public: int f(); };
int C::f() { return *(int*)((char*)this + 0x10) + 0x10; }