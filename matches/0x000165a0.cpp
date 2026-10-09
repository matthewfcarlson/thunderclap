typedef unsigned int u32;
struct A { A* f2(); void f3(int); void f4(u32); };
struct X { A* f1(); };
struct CInvincibleAction { char pad[0x1c]; X* mAt1c; u32 mAt20; void vfunc_4(); };
void CInvincibleAction::vfunc_4() {
 A* a=mAt1c->f1(); A* b=a->f2(); b->f3(0); b->f4(mAt20);
}