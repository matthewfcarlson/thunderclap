// STATUS: equivalent (tools/equiv.py level 3: 462 inputs, branch coverage 6/6)
// physics::CollisionObject::vfunc_5 @ 0x00305400
void* __cdecl FUN_00263ea0(unsigned int);
struct Copy8 { char data[8]; void FUN_0027af70(const Copy8*); };
struct Link { int first, second; unsigned char a,b; char pad[2]; int resolvedFirst,resolvedSecond; };
struct Links { int count; int capacity; Link* items; int other; void FUN_00304da0(const Links*); };
struct State { char data[24]; void FUN_00305210(const State*); };
struct Shape { Shape* FUN_00306c60(); int FUN_00306190(int,unsigned int); };
namespace physics {
struct CollisionObject {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual CollisionObject* vfunc_5(int); virtual void vfunc_6(); virtual void vfunc_7();
 int unknown4; Copy8 name; Copy8 otherName; int owner; int flags; Shape* shape; int value24; Links links; State state; unsigned char flag50,flag51; char pad52[2]; int value54,value58,value5c,value60,value64; char pad68[2]; unsigned char flag6a,flag6b; int value6c; unsigned char flag70,flag71,flag72; char tail[13];
 CollisionObject* FUN_00304ed0(); void FUN_00304b40(Shape*);
};
CollisionObject* CollisionObject::vfunc_5(int newOwner) {
 void* memory=FUN_00263ea0(128);
 CollisionObject* result=memory ? static_cast<CollisionObject*>(memory)->FUN_00304ed0() : 0;
 result->name.FUN_0027af70(&name);
 result->shape=0;
 result->flags=flags;
 Shape* cloned=shape->FUN_00306c60();
 result->FUN_00304b40(cloned);
 result->owner=newOwner;
 result->otherName.FUN_0027af70(&otherName);
 result->value24=value24;
 result->links.FUN_00304da0(&links);
 result->state.FUN_00305210(&state);
 result->flag50=flag50; result->flag51=flag51; result->value54=value54; result->value6c=value6c;
 result->flag71=flag71; result->flag72=flag72; result->flag6a=flag6a; result->flag6b=flag6b;
 result->value58=value58; result->value5c=value5c; result->value60=value60; result->value64=value64;
 for(int i=0;i<links.count;++i) {
 Link* entry=&result->links.items[i];
 int resolved=result->shape->FUN_00306190(entry->first,entry->a);
 entry->resolvedFirst=resolved;
 resolved=result->shape->FUN_00306190(entry->second,entry->b);
 entry->resolvedSecond=resolved;
 }
 return result;
}
}
