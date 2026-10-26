// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 17/18, incomplete)
// FUN_00027fc0 @ 0x00027fc0
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/unknown.h"

typedef unsigned __int64 Key_27fc0;
extern Key_27fc0 __cdecl FUN_002672f0(unsigned, unsigned, unsigned);
struct Node { char pad[0x14]; Node* next; };
struct Handle_27fc0 { Node* node; bool FUN_00231ee0(); };
struct Object { char pad[0xdc]; Handle_27fc0 handle; };
struct Lookup_27fc0 { Node* FUN_00233580(unsigned); };
struct Result_27fc0 { char pad[0x5c]; Lookup_27fc0* lookup; };
struct Manager_27fc0 { Result_27fc0* FUN_000240b0(unsigned); };
struct Owner_27fc0 { Object* FUN_00024280(Key_27fc0); bool FUN_00027fc0(unsigned key, unsigned name); };
bool Owner_27fc0::FUN_00027fc0(unsigned key, unsigned name) {
 if (!name) return false;
 Object* object = FUN_00024280(FUN_002672f0(key, 0, 0));
 if (!object) return false;
 Handle_27fc0* handle = &object->handle;
 if (!handle) return false;
 Node* node = handle->node;
 if (!node || !handle->FUN_00231ee0()) return false;
 Result_27fc0* result = (*(Manager_27fc0**)&DAT_004e5af8)->FUN_000240b0((*(hulk_uintptr*)&DAT_0048e060));
 Node* target = result->lookup->FUN_00233580(name);
 if (!target) return false;
 for (Node* p = node->next; p; p = p->next) {
  if (p == target) return true;
 }
 return false;
}