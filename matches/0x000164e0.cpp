class CSmartPropEventAction { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual bool vfunc_6(int); virtual void f7(); virtual void f8(); char pad[0x18]; void *mA; int mType; void *mB; };
struct Sub { int query(int); };
struct Obj { char pad[0x40]; int value; char pad2[0xa8]; Sub *sub; void mutate(int); int finish(int); };
struct A { void *next(); }; struct B { void *next(); Obj *find(void *); };
bool CSmartPropEventAction::vfunc_6(int x) { A *a=(A*)mA; void *p=a->next(); B *b=(B*)p; p=b->next(); Obj *o=((B*)p)->find(mB); if(o){ int old=o->value; o->mutate(mType); int cur=o->value; if(cur!=old || mType==3){ int n=o->sub->query(cur); if(n>0)o->finish(n); } } return false; }