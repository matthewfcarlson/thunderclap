// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 21/22, incomplete)
// FUN_00027f00 @ 0x00027f00
#include "decls/address.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/unknown.h"
typedef unsigned __int64 Key_27f00;
struct Item_27f00 { char pad[8]; unsigned low; unsigned high; };
struct Handle_27f00 { Item_27f00* item; bool FUN_00231ee0(); };
struct Object { char pad[0xdc]; Handle_27f00 handle; };
struct Root_27f00 { void* FUN_00233580(const char* path); };
struct Context { char pad[0x5c]; Root_27f00* root; };
struct Manager_27f00 { Context* FUN_000240b0(void* key); };
extern char DAT_0048e090;
extern char DAT_0048e0ac;
extern Item_27f00* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
struct Target_27f00 {
 Object* FUN_00024280(Key_27f00 key);
 bool FUN_00027f00(const char* name, const char* path);
};
bool Target_27f00::FUN_00027f00(const char* name, const char* path) {
 if (!path) return false;
 Key_27f00 key = FUN_002672f0(name,0,0);
 Object* object = FUN_00024280(key);
 if (!object) return false;
 Handle_27f00* handle = &object->handle;
 if (!handle) return false;
 Item_27f00* item = handle->item;
 if (!item) return false;
 if (!handle->FUN_00231ee0()) return false;
 if (path[0] == '/') {
 Context* context = (*(Manager_27f00**)&DAT_004e5af8)->FUN_000240b0((*(void**)&DAT_0048e060));
 void* found = context->root->FUN_00233580(path);
 if (!found) return false;
 Item_27f00* result = FUN_00344e74(found,0,&DAT_0048e090,&DAT_0048e0ac,0);
 if (!result) return false;
 return result == item;
 }
 Key_27f00 other = FUN_0027b020(path);
 return item->low == (unsigned)other && item->high == (unsigned)(other >> 32);
}
