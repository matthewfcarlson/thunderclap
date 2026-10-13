// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 8/8)
// FUN_0027db30 @ 0x0027db30
typedef unsigned int U;
struct Spawned;
typedef void (__fastcall *ApplyMethod)(Spawned*, U, U);
struct SpawnVtable { ApplyMethod slots[7]; };
struct Record { U x; unsigned short id; char pad[6]; };
struct Selector { char pad[0x3c]; Record* records; unsigned char FUN_00298960(U* value); };
struct Owner { char pad[0x44]; Selector* selector; };
struct Service { void FUN_002fe6b0(U value); };
struct Entity {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual U v4(U id,U zero);
 char pad[0x80]; unsigned char active;
 Spawned* FUN_002fdf40(U id,U a,U b);
 U FUN_002ef4a0();
 void FUN_002fd4a0(); void FUN_002fd4b0(U id,U zero); void FUN_002fd4f0();
};
struct Holder { char pad[0x10]; Entity* entity; };
struct Spawned {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(U value);
 char pad[0x6c]; Service* service;
 void FUN_002ef440(U value);
};
struct Transform { char pad[0x50]; U position[3]; U rotation[3]; };
struct Child { virtual void v0(); char pad[0xc]; Transform* transform; };
struct Parent { Child* FUN_002fc880(Spawned* object,U zero); };
extern U DAT_00554c10;
struct Target { char pad[0x9c]; Owner* owner; Holder* holder; void run(Parent* parent,U a,U b,U x,U y,U z,U rx,U ry,U rz); };
void Target::run(Parent* parent,U a,U b,U x,U y,U z,U rx,U ry,U rz) {
 if (!holder || !holder->entity->active) return;
 unsigned char selection = owner->selector->FUN_00298960(&a);
 U id = owner->selector->records[selection].id;
 Spawned* object = holder->entity->FUN_002fdf40(id,a,b);
 if (!object) return;
 U value = holder->entity->FUN_002ef4a0();
 object->FUN_002ef440(value);
 object->service->FUN_002fe6b0(DAT_00554c10);
 Entity* entity = holder->entity;
 SpawnVtable* table = *reinterpret_cast<SpawnVtable**>(object);
 value = entity->v4(id,0);
 table->slots[6](object,0,value);
 entity->FUN_002fd4a0();
 entity->FUN_002fd4b0(id,0);
 entity->FUN_002fd4f0();
 Child* child = parent ? parent->FUN_002fc880(object,0) : 0;
 Transform* transform = child->transform;
 transform->position[0]=x;
 transform->position[1]=y;
 transform->position[2]=z;
 transform = child->transform;
 transform->rotation[0]=rx;
 transform->rotation[1]=ry;
 transform->rotation[2]=rz;
 child->v0();
}
