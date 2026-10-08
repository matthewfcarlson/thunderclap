struct C { void* a; void* f592a0(); void* f59a30(); void f373e0(int); };
struct MoveJointAction { char pad[0x20]; C* mObj; void vfunc_4(); };
void MoveJointAction::vfunc_4() { C* p = (C*)mObj; p = (C*)p->f592a0(); p = (C*)p->f59a30(); p->f373e0(1); }