struct Inner { void Helper(void*, void*, void*); };
struct C { char pad[0x18]; Inner inner; void Target(void*, void*); };
void C::Target(void* a, void* b) { inner.Helper(this, a, b); }