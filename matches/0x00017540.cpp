struct A { A* get(); A* valid(); void apply(void*, int); };
class COrientTargetAction { public: char pad[0x1c]; A* m1; char pad20[8]; void* m28; void vfunc_4(); };
void COrientTargetAction::vfunc_4() { A* a = m1->get(); a = a->valid(); if (a) a->apply(m28, 0); }