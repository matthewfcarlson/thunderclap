// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 17/18, incomplete)
// FUN_00028050 @ 0x00028050
typedef unsigned __int64 Key;
extern Key __cdecl FUN_002672f0(const char*, int, int);
struct Node { char pad[0x14]; Node* parent; };
struct Handle { Node* node; bool FUN_00231ee0(); };
struct Entry { char pad[0xb4]; Handle handle; };
struct Tree { Node* FUN_00233580(const char*); };
struct Context { char pad[0x5c]; Tree* tree; };
struct Manager { Context* FUN_000240b0(unsigned int); };
extern unsigned int DAT_0048e064;
extern Manager* DAT_004e5af8;
struct Object { Entry* FUN_00024280(Key); bool FUN_00028050(const char*, const char*); };
bool Object::FUN_00028050(const char* name, const char* ancestor) {
 if (!ancestor) return false;
 Key key = FUN_002672f0(name, 0, 0);
 Entry* entry = FUN_00024280(key);
 if (!entry) return false;
 Handle* handle = &entry->handle;
 if (!handle) return false;
 Node* node = handle->node;
 if (!node || !handle->FUN_00231ee0()) return false;
 Context* context = DAT_004e5af8->FUN_000240b0(DAT_0048e064);
 Node* target = context->tree->FUN_00233580(ancestor);
 if (!target) return false;
 for (Node* parent = node->parent; parent; parent = parent->parent) {
  if (parent == target) return true;
 }
 return false;
}