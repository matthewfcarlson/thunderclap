// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// FUN_000385a0 @ 0x000385a0
#include "decls/address.h"
struct Handle_385a0;
struct Entity;
struct Resolver_385a0 { Handle_385a0* FUN_001d6490(); };
struct Manager_385a0 { bool FUN_000242d0(void* object); };
struct World { char pad[0x20]; Manager_385a0* manager; };
struct Handle_385a0 {
 virtual void retain();
 virtual void release();
 unsigned int reserved;
 void* object;
 unsigned int kind;
};
void __cdecl FUN_00018810(Handle_385a0** destination, Handle_385a0* source);
struct Entity {
 char pad[0x22e4];
 Handle_385a0* handle;
 void FUN_000385a0(Handle_385a0* replacement, bool force);
};
void Entity::FUN_000385a0(Handle_385a0* replacement, bool force) {
 if (!force && handle && handle->kind == 1) {
  if (DAT_004dd700->manager->FUN_000242d0(handle->object)) return;
 }
 if (replacement) replacement->retain();
 if (handle) handle->release();
 handle = replacement;
 if (!replacement) return;
 if (replacement->kind == 5) {
  Resolver_385a0* resolver = static_cast<Resolver_385a0*>(replacement->object);
  if (resolver->FUN_001d6490()) {
   Handle_385a0* resolved = resolver->FUN_001d6490();
   FUN_00018810(&handle, resolved);
  }
 } else if (replacement->kind == 1) {
  Entity* entity = static_cast<Entity*>(replacement->object);
  if (!DAT_004dd700->manager->FUN_000242d0(entity)) {
   Handle_385a0* resolved = entity->handle;
   if (resolved) FUN_00018810(&handle, resolved);
  }
 }
}
