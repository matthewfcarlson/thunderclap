// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// hulkfight::motion::FireProjectileAction::vfunc_3 @ 0x001951a0
struct Ref { virtual void AddRef() = 0; virtual void Release() = 0; unsigned reserved; void* data; };
struct Lookup { unsigned FUN_0027b200(unsigned,unsigned); };
struct ActorInfo { char pad[0x74]; void* value; };
struct Actor { ActorInfo* FUN_001d72e0(); Ref* FUN_001d68d0(); };
struct World { char pad[0x120]; Ref* object; Actor* FUN_00035ef0(int); };
struct Context { World* FUN_00059a30(); };
struct Owner { Context* FUN_000592a0(); };
void __cdecl FUN_000188e0(Actor**, Actor*);
void __cdecl FUN_00037510(Ref**, Ref*);
struct Config { char pad[0x2c]; float duration; int index; unsigned unused; unsigned key1; unsigned key2; };
namespace hulkfight { namespace motion {
struct FireProjectileAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(unsigned,unsigned); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x18]; Config* config; Owner* owner; float rate; Actor* actor; Ref* object; unsigned id;
};
bool FireProjectileAction::vfunc_3(unsigned,unsigned) {
 if (!owner) return false;
 if (config->duration > 0.0f) rate = 1.0f / config->duration;
 Context* context = owner->FUN_000592a0();
 World* world = context->FUN_00059a30();
 Ref* next = world->object;
 if(next) next->AddRef();
 if(object) object->Release();
 object = next;
 int index = config->index;
 if(index >= 0 && index < 8) {
 Actor* found = world->FUN_00035ef0(index);
 if(found) {
 if(!found->FUN_001d72e0() || !found->FUN_001d72e0()->value) FUN_000188e0(&actor,found);
 Ref* r = found->FUN_001d68d0();
 FUN_00037510(&object,r);
 }
 }
 Ref* current = object;
 if(current) {
 unsigned a = config->key1; unsigned b = config->key2;
 Lookup* lookup = (Lookup*)current->data;
 if(a | b) {
 id = lookup->FUN_0027b200(a,b);
 if(id == 0xffff) id = 0;
 }
 }
 return true;
}
}}
