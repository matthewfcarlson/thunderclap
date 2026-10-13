// STATUS: equivalent (tools/equiv.py level 3: 535 inputs, branch coverage 31/32, incomplete)
// FUN_0007da70 @ 0x0007da70
struct Group { char pad[0x59c]; int id; int FUN_002042a0(int index,int id); };
struct Resolver { Group* FUN_000862a0(); };
struct Owner { char pad[0x54]; Resolver* resolver; };
struct Slot { int id; char pad[0x3ec]; };
struct Item { char pad[0x10]; int type; char pad2[0x24]; int id; };
struct State { char pad[0x1920]; Slot slots[7]; char pad2[0x374c-0x1920-7*0x3f0]; Item* items[20]; int count; char pad3[0x382c-0x37a0]; Owner* owner; int current; void FUN_0007b880(int index); void FUN_0007bbd0(int id); void target(int unused); };
void State::target(int unused) {
 Group* group=owner->resolver->FUN_000862a0();
 int ids[7]; ids[0]=group->id;
 if(ids[0]==current) return;
 current=ids[0];
 for(int i=0;i<6;++i) ids[i+1]=group->FUN_002042a0(i,ids[0]);
 for(int s=0;s<7;++s) { if(slots[s].id!=0) { int j; for(j=0;j<7;++j) if(slots[s].id==ids[j]) break; if(j==7) slots[s].id=0; } }
 for(int k=0;k<count;++k) { Item* item=items[k]; if(item->type!=0x13) { int j; for(j=0;j<7;++j) if(item->id==ids[j]) break; if(j==7) { FUN_0007b880(k); --k; } } }
 for(int n=0;n<7;++n) { if(ids[n]!=-1) { int j; for(j=0;j<7;++j) if(slots[j].id==ids[n]) break; if(j==7) FUN_0007bbd0(ids[n]); } }
}
