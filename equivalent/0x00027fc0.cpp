// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 17/18, incomplete)
// FUN_00027fc0 @ 0x00027fc0
typedef unsigned __int64 Key;
extern Key __cdecl FUN_002672f0(unsigned, unsigned, unsigned);
struct Node { char pad[0x14]; Node* next; };
struct Handle { Node* node; bool FUN_00231ee0(); };
struct Object { char pad[0xdc]; Handle handle; };
struct Lookup { Node* FUN_00233580(unsigned); };
struct Result { char pad[0x5c]; Lookup* lookup; };
struct Manager { Result* FUN_000240b0(unsigned); };
extern unsigned DAT_0048e060;
extern Manager* DAT_004e5af8;
struct Owner { Object* FUN_00024280(Key); bool FUN_00027fc0(unsigned key, unsigned name); };
bool Owner::FUN_00027fc0(unsigned key, unsigned name) {
 if (!name) return false;
 Object* object = FUN_00024280(FUN_002672f0(key, 0, 0));
 if (!object) return false;
 Handle* handle = &object->handle;
 if (!handle) return false;
 Node* node = handle->node;
 if (!node || !handle->FUN_00231ee0()) return false;
 Result* result = DAT_004e5af8->FUN_000240b0(DAT_0048e060);
 Node* target = result->lookup->FUN_00233580(name);
 if (!target) return false;
 for (Node* p = node->next; p; p = p->next) {
  if (p == target) return true;
 }
 return false;
}