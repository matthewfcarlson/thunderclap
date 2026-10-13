// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// CDropAction::vfunc_6 @ 0x00013d70
struct Vec { float x,y,z; };
struct Transform { float data; float FUN_002220d0(); void FUN_00221be0(Transform*); };
struct Name { int data; void FUN_0027b040(const char*); };
struct Obj { virtual void vfunc_0(); char pad[4]; Name name; char pad2[12]; Transform transform; Obj* FUN_002248f0(int); };
struct Body { char pad[16]; Transform transform; void FUN_00222890(Obj*,float,float,float,float,float,float); };
struct Position { void FUN_000356c0(Vec*); };
struct Actor { Position* FUN_00059a30(); Body* FUN_00059a40(); };
struct Owner { Actor* FUN_000592a0(); };
struct Config { char pad[20]; float height; char pad2[8]; unsigned char usePosition; char pad3[3]; float depth; char pad4[8]; float a,b,c; };
void* __cdecl FUN_00263ea0(unsigned int);
struct CDropAction { char pad[28]; Owner* owner; Config* config; Obj* object; float height,depth; bool vfunc_6(int); };
bool CDropAction::vfunc_6(int) {
 Actor* actor=owner->FUN_000592a0();
 Position* position=actor->FUN_00059a30();
 Body* body=actor->FUN_00059a40();
 if(!body) return false;
 if(config->usePosition) { Vec p; p.x=p.y=p.z=0.0f; position->FUN_000356c0(&p); depth=p.y; }
 else depth=-config->depth;
 float h=config->height;
 Transform* transform=&body->transform;
 height=transform->FUN_002220d0()+h;
 float a=config->a,b=config->b,c=config->c;
 Obj* allocated=(Obj*)FUN_00263ea0(0x70);
 Obj* result=allocated ? allocated->FUN_002248f0(0) : 0;
 object=result;
 result->name.FUN_0027b040("drop");
 object->vfunc_0();
 object->transform.FUN_00221be0(transform);
 body->FUN_00222890(object,-1.0f,a,1.0f,b,c,-1.0f);
 return true;
}