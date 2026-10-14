// STATUS: equivalent (tools/equiv.py level 3: 93 inputs, branch coverage 18/18)
// physics::CollisionObject::vfunc_7 @ 0x00305070
struct Entry_305070 { unsigned char kind; char padding[11]; };
struct Item_305070 { char data[8]; };
struct Group_305070 { int count; int reserved; Item_305070* items; int reserved2; };
struct Manager_305070 { char pad[0x24]; unsigned char* mapping; char pad2[0x14]; Entry_305070* begin; Entry_305070* end; unsigned char FUN_00298960(Item_305070*); };
struct Context { char pad[0x44]; Manager_305070* manager; };
struct Owner_305070 { void FUN_003062a0(); };
namespace physics {
struct CollisionObject {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void* vfunc_7(Context*);
char pad[0x1c]; Owner_305070* owner; char pad2[0x14]; int count; Group_305070* groups; int result; Manager_305070* manager; unsigned char* states;
void FUN_00304c40(Owner_305070*, int*);
};
void* CollisionObject::vfunc_7(Context* context) {
 bool changed=false;
 for(int i=0;i<count;++i) {
  unsigned char active=0;
  for(int j=0;j<groups[i].count;++j) {
   Manager_305070* m=context->manager;
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