class A { public: void* f(); };
class B { public: void* f(int); };
class C { public: void f(); };
extern A* gGlobal;
class CHapticEventAction { public: char pad[0x20]; void* mEvent; void vfunc_4(); };
void CHapticEventAction::vfunc_4() { if (*((char*)mEvent + 0x1c)) { void* p = gGlobal->f(); B* b = (B*)p; C* c = (C*)b->f(0); c->f(); } }