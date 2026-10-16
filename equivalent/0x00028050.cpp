// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 17/18, incomplete)
// FUN_00028050 @ 0x00028050
#include "decls/address.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/unknown.h"
typedef unsigned __int64 Key_28050;
struct Node { char pad[0x14]; Node* parent; };
struct Handle_28050 { Node* node; bool FUN_00231ee0(); };
struct Entry_28050 { char pad[0xb4]; Handle_28050 handle; };
struct Tree_28050 { Node* FUN_00233580(const char*); };
struct Context { char pad[0x5c]; Tree_28050* tree; };
struct Manager_28050 { Context* FUN_000240b0(unsigned int); };
struct Object { Entry_28050* FUN_00024280(Key_28050); bool FUN_00028050(const char*, const char*); };
bool Object::FUN_00028050(const char* name, const char* ancestor) {
 if (!ancestor) return false;
 Key_28050 key = FUN_002672f0(name, 0, 0);
 Entry_28050* entry = FUN_00024280(key);
 if (!entry) return false;
 Handle_28050* handle = &entry->handle;
 if (!handle) return false;
 Node* node = handle->node;
 if (!node || !handle->FUN_00231ee0()) return false;
 Context* context = (*(Manager_28050**)&DAT_004e5af8)->FUN_000240b0((*(unsigned int*)&DAT_0048e064));
 Node* target = context->tree->FUN_00233580(ancestor);
 if (!target) return false;
 for (Node* parent = node->parent; parent; parent = parent->parent) {
  if (parent == target) return true;
 }
 return false;
}