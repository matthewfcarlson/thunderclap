class C { public: char pad[0xa0]; void* p; int get(); };
int C::get() { if (p) return *(int*)((char*)p + 0x10); return 0; }