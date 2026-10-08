class TargetBreakAction { public: char pad[0x1c]; void* mThing; void vfunc_4(); };
struct Obj { char pad[0x12c]; int id; };
struct Entry { char pad[0x328]; int id; char flag; };
struct Manager { char pad[0xc]; int count; Entry* get(int); };
struct Root { char pad[0x20]; Manager* manager; };
struct A { void* call(); }; struct B { void* call(); }; struct E { void call(); };
extern A* aFn; extern B* bFn; extern E* eFn; extern Root* gRoot;
void TargetBreakAction::vfunc_4() {
 void* a=((A*)mThing)->call(); if(a) { Obj* b=(Obj*)a; b=(Obj*) ((B*)a)->call(); if(b) { int id=b->id; if(id) { Manager* m=gRoot->manager; int count=m->count; for(int i=0;i<count;++i) { Entry* e=m->get(i); if(e->id==id) { ((E*)e)->call(); e->flag=0; } } } } }
}