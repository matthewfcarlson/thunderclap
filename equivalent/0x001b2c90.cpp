// STATUS: equivalent (tools/equiv.py level 3: 3060 inputs, branch coverage 26/26)
// AICollisionSolverAgent::vfunc_7 @ 0x001b2c90
struct Vec { float x,y,z; float FUN_0022d110(); void FUN_00011140(float); };
struct Body;
struct Actor { char pad[0x114]; Body* linked1; Body* linked2; char pad2[0x30]; unsigned char active; };
struct Tag { char pad[8]; unsigned int a,b; };
struct Body { char pad[8]; Actor* actor; int kind; char pad2[0x64]; Tag* tag; };
struct ContactObject { char pad[0x18]; Body* body; };
struct Contact { char pad[8]; ContactObject* first; ContactObject* second; };
struct Manager { bool FUN_00079950(void*); };
struct Global { char pad[0x4c]; Manager* manager; };
extern Global* DAT_004dd700;
extern unsigned int DAT_004e2198, DAT_004e219c;
extern float DAT_004c37f8;
extern "C" double __cdecl sqrt(double);
struct AICollisionSolverAgent {
 void FUN_001b1080(Actor*,Actor*,Vec*,Body*);
 void FUN_001b1270(Actor*,Actor*,Vec*,Contact*,Body*,Body*);
 int vfunc_7(Vec*,Contact*);
};
int AICollisionSolverAgent::vfunc_7(Vec* v, Contact* c) {
 Body* first=c->first->body; Body* second=c->second->body;
 if(first->kind==5) {
 if(second->kind==1) FUN_001b1080(first->actor,second->actor,v,second);
 else if(second->kind==5) FUN_001b1270(first->actor,second->actor,v,c,first,second);
 }
 if(second->kind==5) {
 Actor* a=second->actor;
 if(first!=a->linked1 && first!=a->linked2 && first->kind==1) FUN_001b1080(a,first->actor,v,first);
 }
 if(first->kind==5) {
 Tag* t=second->tag;
 if(t->a==DAT_004e2198 && t->b==DAT_004e219c) {
 Actor* a=first->actor;
 if(a->active && !DAT_004dd700->manager->FUN_00079950((char*)a+8)) {
 if(sqrt((double)v->x*v->x+(double)v->y*v->y+(double)v->z*v->z)>=DAT_004c37f8) {
 v->FUN_0022d110(); v->FUN_00011140(DAT_004c37f8);
 }
 }
 }
 }
 return 0;
}
