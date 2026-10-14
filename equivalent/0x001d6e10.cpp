// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// FUN_001d6e10 @ 0x001d6e10
struct Entry;
struct Owner;
struct Resource {
 Entry* FUN_00035b60();
};
struct Entry {
 virtual void AddRef();
 virtual void Release();
 unsigned int reserved;
 union { Resource* resource; Owner* owner; } value;
 unsigned int type;
};
struct Manager { bool FUN_000242d0(Resource*); };
struct Global { char pad[0x20]; Manager* manager; };
extern Global* DAT_004dd700;
void __cdecl FUN_00018810(Entry**, Entry*);
struct Owner {
 char pad[0x24c];
 Entry* entry;
 void FUN_001d6e10(Entry* incoming);
};
void Owner::FUN_001d6e10(Entry* incoming) {
 if (entry && entry->type == 1 && DAT_004dd700->manager->FUN_000242d0(entry->value.resource)) return;
 if (incoming) incoming->AddRef();
 if (entry) entry->Release();
 entry = incoming;
 if (!incoming) return;
 if (incoming->type == 5) {
  Entry* nested = incoming->value.owner->entry;
  if (nested) FUN_00018810(&entry, nested);
 } else if (incoming->type == 1) {
  Resource* resource = incoming->value.resource;
  if (!DAT_004dd700->manager->FUN_000242d0(resource) && resource->FUN_00035b60())
   FUN_00018810(&entry, resource->FUN_00035b60());
 }
}
