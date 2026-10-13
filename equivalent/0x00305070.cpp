// STATUS: equivalent (tools/equiv.py level 3: 93 inputs, branch coverage 18/18)
// physics::CollisionObject::vfunc_7 @ 0x00305070
struct Entry { unsigned char kind; char padding[11]; };
struct Item { char data[8]; };
struct Group { int count; int reserved; Item* items; int reserved2; };
struct Manager { char pad[0x24]; unsigned char* mapping; char pad2[0x14]; Entry* begin; Entry* end; unsigned char FUN_00298960(Item*); };
struct Context { char pad[0x44]; Manager* manager; };
struct Owner { void FUN_003062a0(); };
namespace physics {
struct CollisionObject {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void* vfunc_7(Context*);
char pad[0x1c]; Owner* owner; char pad2[0x14]; int count; Group* groups; int result; Manager* manager; unsigned char* states;
void FUN_00304c40(Owner*, int*);
};
void* CollisionObject::vfunc_7(Context* context) {
 bool changed=false;
 for(int i=0;i<count;++i) {
  unsigned char active=0;
  for(int j=0;j<groups[i].count;++j) {
   Manager* m=context->manager;
   unsigned char index=m->FUN_00298960(&groups[i].items[j]);
   unsigned char n=(unsigned char)(m->end-m->begin);
   if(index<n && m->mapping[index]!=255 && m->begin[index].kind==1) { active=1; break; }
  }
  if(states[i]!=active) { states[i]=active; changed=true; }
 }
 if(changed) { FUN_00304c40(owner,&result); owner->FUN_003062a0(); }
 return &result;
}
}