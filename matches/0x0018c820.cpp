// Same code shape as 0x0014c420 (propagated; names are from that function)
void* __cdecl alloc(unsigned int);
struct Obj { void* init(); };
void* f() { Obj* p = (Obj*)alloc(0x30); if (p) return p->init(); return 0; }