class A { public: void* f(); };
class B { public: void* g(); void h(void*); };
class MotionBoostAction { public: char pad[0x20]; void* member; char rest[0x20]; bool vfunc_3(int, int); };
bool MotionBoostAction::vfunc_3(int, int) { if (!member) return false; void* x = ((A*)member)->f(); x = ((B*)x)->g(); ((B*)x)->h((char*)this + 0x28); return true; }