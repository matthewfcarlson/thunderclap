// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// FUN_000385a0 @ 0x000385a0
struct Handle;
struct Entity;
struct Resolver { Handle* FUN_001d6490(); };
struct Manager { bool FUN_000242d0(void* object); };
struct Globals { char pad[0x20]; Manager* manager; };
extern Globals* DAT_004dd700;
struct Handle {
 virtual void retain();
 virtual void release();
 unsigned int reserved;
 void* object;
 unsigned int kind;
};
void __cdecl FUN_00018810(Handle** destination, Handle* source);
struct Entity {
 char pad[0x22e4];
 Handle* handle;
 void FUN_000385a0(Handle* replacement, bool force);
};
void Entity::FUN_000385a0(Handle* replacement, bool force) {
 if (!force && handle && handle->kind == 1) {
  if (DAT_004dd700->manager->FUN_000242d0(handle->object)) return;
 }
 if (replacement) replacement->retain();
 if (handle) handle->release();
 handle = replacement;
 if (!replacement) return;
 if (replacement->kind == 5) {
  Resolver* resolver = static_cast<Resolver*>(replacement->object);
  if (resolver->FUN_001d6490()) {
   Handle* resolved = resolver->FUN_001d6490();
   FUN_00018810(&handle, resolved);
  }
 } else if (replacement->kind == 1) {
  Entity* entity = static_cast<Entity*>(replacement->object);
  if (!DAT_004dd700->manager->FUN_000242d0(entity)) {
   Handle* resolved = entity->handle;
   if (resolved) FUN_00018810(&handle, resolved);
  }
 }
}
