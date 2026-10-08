class C { public: int pad[2]; void* ptr; int f(); };
int C::f() { if (!ptr) return 0; return *(int*)((char*)ptr + 0x10); }