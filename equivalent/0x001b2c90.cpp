// STATUS: equivalent (tools/equiv.py level 3: 3060 inputs, branch coverage 26/26)
// AICollisionSolverAgent::vfunc_7 @ 0x001b2c90
#include "gen/global.h"
#include "decls/address.h"
#include "decls/data/game/global.h"

struct Vec_1b2c90 { float x,y,z; float FUN_0022d110(); void FUN_00011140(float); };
struct Body_1b2c90;
struct Actor_1b2c90 { char pad[0x114]; Body_1b2c90* linked1; Body_1b2c90* linked2; char pad2[0x30]; unsigned char active; };
struct Tag_1b2c90 { char pad[8]; unsigned int a,b; };
struct Body_1b2c90 { char pad[8]; Actor_1b2c90* actor; int kind; char pad2[0x64]; Tag_1b2c90* tag; };
struct ContactObject { char pad[0x18]; Body_1b2c90* body; };
struct Contact_1b2c90 { char pad[8]; ContactObject* first; ContactObject* second; };
struct Manager_1b2c90 { bool FUN_00079950(void*); };
struct World { char pad[0x4c]; Manager_1b2c90* manager; };
extern "C" double __cdecl sqrt(double);
struct AICollisionSolverAgent_nv_1b2c90 {
    void FUN_001b1080(Actor_1b2c90*,Actor_1b2c90*,Vec_1b2c90*,Body_1b2c90*);
    void FUN_001b1270(Actor_1b2c90*,Actor_1b2c90*,Vec_1b2c90*,Contact_1b2c90*,Body_1b2c90*,Body_1b2c90*);
};

int AICollisionSolverAgent::vfunc_7(void* __p0, int __p1) { Vec_1b2c90 * v = (Vec_1b2c90 *)__p0; Contact_1b2c90 * c = (Contact_1b2c90 *)__p1;

 Body_1b2c90* first=c->first->body; Body_1b2c90* second=c->second->body;
 if(first->kind==5) {
 if(second->kind==1) ((AICollisionSolverAgent_nv_1b2c90*)this)->FUN_001b1080(first->actor,second->actor,v,second);
 else if(second->kind==5) ((AICollisionSolverAgent_nv_1b2c90*)this)->FUN_001b1270(first->actor,second->actor,v,c,first,second);
 }
 if(second->kind==5) {
 Actor_1b2c90* a=second->actor;
 if(first!=a->linked1 && first!=a->linked2 && first->kind==1) ((AICollisionSolverAgent_nv_1b2c90*)this)->FUN_001b1080(a,first->actor,v,first);
 }
 if(first->kind==5) {
 Tag_1b2c90* t=second->tag;
 if(t->a==DAT_004e2198 && t->b==(*(unsigned int*)&DAT_004e219c)) {
 Actor_1b2c90* a=first->actor;
 if(a->active && !DAT_004dd700->manager->FUN_00079950((char*)a+8)) {
 if(sqrt((double)v->x*v->x+(double)v->y*v->y+(double)v->z*v->z)>=DAT_004c37f8) {
 v->FUN_0022d110(); v->FUN_00011140(DAT_004c37f8);
 }
 }
 }
 }
 return 0;
}
