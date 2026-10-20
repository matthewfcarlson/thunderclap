// STATUS: equivalent (tools/equiv.py level 3: 20018 inputs, branch coverage 8/8)
// FUN_0027db30 @ 0x0027db30
#include "decls/data/game/global.h"
#include "gen/physics.h"

typedef unsigned int U_27db30;
struct Spawned_27db30;
typedef void (__fastcall *ApplyMethod)(Spawned_27db30*, U_27db30, U_27db30);
struct SpawnVtable { ApplyMethod slots[7]; };
struct Record_27db30 { U_27db30 x; unsigned short id; char pad[6]; };
struct Selector_27db30 { char pad[0x3c]; Record_27db30* records; unsigned char FUN_00298960(U_27db30* value); };
struct Owner_27db30 { char pad[0x44]; Selector_27db30* selector; };
struct Service_27db30 { void FUN_002fe6b0(U_27db30 value); };
struct Entity_27db30 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual U_27db30 v4(U_27db30 id,U_27db30 zero);
 char pad[0x80]; unsigned char active;
 Spawned_27db30* FUN_002fdf40(U_27db30 id,U_27db30 a,U_27db30 b);
 U_27db30 FUN_002ef4a0();
 void FUN_002fd4a0(); void FUN_002fd4b0(U_27db30 id,U_27db30 zero); void FUN_002fd4f0();
};
struct Holder_27db30 { char pad[0x10]; Entity_27db30* entity; };
struct Spawned_27db30 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(U_27db30 value);
 char pad[0x6c]; Service_27db30* service;
 void FUN_002ef440(U_27db30 value);
};
struct Transform_27db30 { char pad[0x50]; U_27db30 position[3]; U_27db30 rotation[3]; };
struct Child_27db30 { virtual void v0(); char pad[0xc]; Transform_27db30* transform; };
struct PhysicsInstance_nv_27db30 {
    Child_27db30* FUN_002fc880(Spawned_27db30* object,U_27db30 zero);
};
struct Target_27db30 { char pad[0x9c]; Owner_27db30* owner; Holder_27db30* holder; void run(physics::PhysicsInstance* parent,U_27db30 a,U_27db30 b,U_27db30 x,U_27db30 y,U_27db30 z,U_27db30 rx,U_27db30 ry,U_27db30 rz); };
void Target_27db30::run(physics::PhysicsInstance* parent,U_27db30 a,U_27db30 b,U_27db30 x,U_27db30 y,U_27db30 z,U_27db30 rx,U_27db30 ry,U_27db30 rz) {
 if (!holder || !holder->entity->active) return;
 unsigned char selection = owner->selector->FUN_00298960(&a);
 U_27db30 id = owner->selector->records[selection].id;
 Spawned_27db30* object = holder->entity->FUN_002fdf40(id,a,b);
 if (!object) return;
 U_27db30 value = holder->entity->FUN_002ef4a0();
 object->FUN_002ef440(value);
 object->service->FUN_002fe6b0((*(U_27db30*)&DAT_00554c10));
 Entity_27db30* entity = holder->entity;
 SpawnVtable* table = *reinterpret_cast<SpawnVtable**>(object);
 value = entity->v4(id,0);
 table->slots[6](object,0,value);
 entity->FUN_002fd4a0();
 entity->FUN_002fd4b0(id,0);
 entity->FUN_002fd4f0();
 Child_27db30* child = parent ? ((PhysicsInstance_nv_27db30*)(parent))->FUN_002fc880(object,0) : 0;
 Transform_27db30* transform = child->transform;
 transform->position[0]=x;
 transform->position[1]=y;
 transform->position[2]=z;
 transform = child->transform;
 transform->rotation[0]=rx;
 transform->rotation[1]=ry;
 transform->rotation[2]=rz;
 child->v0();
}
