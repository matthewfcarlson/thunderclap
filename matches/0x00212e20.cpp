typedef unsigned int u32; struct Pair{u32 a,b;}; struct Obj{char pad[8]; Pair* end;};
Pair* __fastcall FUN_00212bb0(Obj*, Obj*);
void FUN_00212e20(Obj* self, Obj* x) { Pair* p=FUN_00212bb0(x,self); Pair* q=self->end; while(q>p){q->a=(q-1)->a;q->b=(q-1)->b;--q;} q=self->end;p->a=q->a;p->b=q->b; }