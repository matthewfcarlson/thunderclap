class Chain { public: Chain *A(); void B(); int C(); void D(); };
class Manager { public: Chain *Get(int); Chain *Get2(int,int); };
class Obj { public: char pad[0x150]; Manager *m; };
int __fastcall target(Obj *self, void *, int x, int y) { Chain *a=self->m->Get(x); a=a->A(); a->B(); Chain *b=self->m->Get2(x,y); int r=b->C(); a=self->m->Get(x); a=a->A(); a->D(); return r; }