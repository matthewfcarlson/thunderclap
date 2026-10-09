struct Block { int a[21]; void Finish(int); };
class Obj { public: char pad0[4]; int value; char pad8[12]; Block source; Block dest; int state; };
extern int __fastcall clone(int);
extern void __fastcall notify(Obj *);
Block * __fastcall target(Obj *p) { if(p->state==2) { if(p->value) { p->dest=p->source; int x=clone(p->value); p->dest.Finish(x); notify(p); } p->state=0; } return &p->dest; }
