// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// CDropAction::vfunc_6 @ 0x00013d70
struct Vec_13d70 { float x,y,z; };
struct Transform_13d70 { float data; float FUN_002220d0(); void FUN_00221be0(Transform_13d70*); };
struct Name_13d70 { int data; void FUN_0027b040(const char*); };
struct JointDriver_13d70 { virtual void vfunc_0(); char pad[4]; Name_13d70 name; char pad2[12]; Transform_13d70 transform; JointDriver_13d70* FUN_002248f0(int); };
struct Body_13d70 { char pad[16]; Transform_13d70 transform; void FUN_00222890(JointDriver_13d70*,float,float,float,float,float,float); };
struct Position_13d70 { void FUN_000356c0(Vec_13d70*); };
struct Actor_13d70 { Position_13d70* FUN_00059a30(); Body_13d70* FUN_00059a40(); };
struct Owner_13d70 { Actor_13d70* FUN_000592a0(); };
struct Config_13d70 { char pad[20]; float height; char pad2[8]; unsigned char usePosition; char pad3[3]; float depth; char pad4[8]; float a,b,c; };
void* __cdecl FUN_00263ea0(unsigned int);
struct CDropAction { char pad[28]; Owner_13d70* owner; Config_13d70* config; JointDriver_13d70* object; float height,depth; bool vfunc_6(int); };
bool CDropAction::vfunc_6(int) {
 Actor_13d70* actor=owner->FUN_000592a0();
 Position_13d70* position=actor->FUN_00059a30();
 Body_13d70* body=actor->FUN_00059a40();
 if(!body) return false;
 if(config->usePosition) { Vec_13d70 p; p.x=p.y=p.z=0.0f; position->FUN_000356c0(&p); depth=p.y; }
 else depth=-config->depth;
 float h=config->height;
 Transform_13d70* transform=&body->transform;
 height=transform->FUN_002220d0()+h;
 float a=config->a,b=config->b,c=config->c;
 JointDriver_13d70* allocated=(JointDriver_13d70*)FUN_00263ea0(0x70);
 JointDriver_13d70* result=allocated ? allocated->FUN_002248f0(0) : 0;
 object=result;
 result->name.FUN_0027b040("drop");
 object->vfunc_0();
 object->transform.FUN_00221be0(transform);
 body->FUN_00222890(object,-1.0f,a,1.0f,b,c,-1.0f);
 return true;
}