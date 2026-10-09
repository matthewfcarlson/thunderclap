void __cdecl Release(void*) throw();
class Base { public: ~Base(); };
class Language : public Base { public: ~Language(); char pad[0x1c]; void* a; void* b; void* c; };
Language::~Language() { *(unsigned long*)this = 0x42fd84; Release(a); Release(b); Release(c); }