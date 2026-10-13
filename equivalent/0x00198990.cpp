// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 4/4)
// FUN_00198990 @ 0x00198990
struct Vec3 { float x,y,z; };
struct Transform { char data[64]; void FUN_0022b980(); };
struct Params { char pad0[44]; unsigned field2c; char pad30[4]; unsigned field34; char pad38[8]; char position[28]; unsigned field5c; };
struct RenderState { char pad[112]; unsigned char enabled; unsigned char other; unsigned char flag; };
struct Object { virtual void AddRef(); virtual void Release(); unsigned field4; void* owner; unsigned type; char pad10[100]; RenderState* state; };
struct AllocObject { AllocObject* FUN_002efe50(Vec3*, unsigned); };
extern void* __cdecl FUN_0008d690(unsigned);
extern Object* __cdecl FUN_002efca0(AllocObject*, unsigned);
struct Controller { void FUN_001b42b0(); };
extern Controller* __stdcall FUN_001b6580(Object*);
struct Manager { unsigned FUN_00283a40(void*, Transform*, float, float); };
extern Manager* __cdecl FUN_0027f250();
struct FUN_001b6800 { FUN_001b6800(); virtual void slot0(); char base[20]; };
namespace hulkfight { namespace motion {
struct ProjectileGroundShockwave : FUN_001b6800 {
 Params* params; unsigned field1c,field20; Object* object; unsigned field28,field2c; float field30; unsigned field34,field38; unsigned cleared[32]; unsigned fieldbc;
 virtual void slot0();
 ProjectileGroundShockwave(Params* p);
};
ProjectileGroundShockwave::ProjectileGroundShockwave(Params* p) {
 params=0; field1c=0; field20=0; object=0; field28=0; field2c=0; field30=-1.0f; field34=0; field38=0; fieldbc=0;
 params=p; *(unsigned*)(base+8)=p->field2c;
 AllocObject* mem=(AllocObject*)FUN_0008d690(72);
 AllocObject* created=0;
 if(mem) { unsigned value=params->field34; Vec3 v; v.x=0; v.y=0; v.z=0; created=mem->FUN_002efe50(&v,value); }
 Object* obj=FUN_002efca0(created,0);
 obj->type=6; obj->owner=this; obj->AddRef();
 if(object) object->Release();
 object=obj;
 RenderState* state=obj->state; state->enabled=1; state->flag=0;
 FUN_001b6580(object)->FUN_001b42b0();
 Transform transform; transform.FUN_0022b980();
 Manager* manager=FUN_0027f250();
 field34=manager->FUN_00283a40(params->position,&transform,-1.0f,1.0f);
 field38=params->field5c;
 for(int i=0;i<32;++i) cleared[i]=0;
}
}}
