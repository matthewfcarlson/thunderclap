// STATUS: equivalent (tools/equiv.py level 3: 85 inputs, branch coverage 21/22, incomplete)
// FUN_00029990 @ 0x00029990
struct Output { char data[12]; };
struct Info { void FUN_00059a50(Output*); };
struct Value { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual int v9(); };
struct Entity { char p0[0x10]; Info* info; char p1[0x334-0x14]; int flag334; int flag338; char p2[0x1b0c-0x33c]; float amount; char p3[0x1ca0-0x1b10]; Value* value; bool FUN_00035ab0(); };
struct Manager { Entity* FUN_00059c10(int); };
struct Owner { char pad[0x44]; Manager* manager; };
struct Target { Owner* owner; char pad[8]; int count; int ids[1]; int FUN_00029990(); };
int Target::FUN_00029990() { int best=0; int n=count; Output output; for(int i=0;i<n;++i) { if(i>=0 && i<count) { Entity* e=owner->manager->FUN_00059c10(ids[i]); if(e) { e->info->FUN_00059a50(&output); if(e->flag338==0 && e->flag334==0 && !(e->amount<=0.0f) && !e->FUN_00035ab0()) { Value* v=e->value; if(v && v->v9()>best) best=v->v9(); } } } } return best; }
