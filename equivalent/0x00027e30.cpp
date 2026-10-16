// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 23/24, incomplete)
// FUN_00027e30 @ 0x00027e30
// Does the named pawn's current item match the item at `path` (or the item with that name hash)?
// Variant of 0x00027f00 that rejects the pawn's excluded item first.
#include "decls/address.h"
typedef unsigned __int64 Key_27e30;
struct Item_27e30 { char pad[8]; unsigned low; unsigned high; };
struct Handle_27e30 { Item_27e30* item; bool FUN_00231ee0(); };
struct Object { char pad[0xdc]; Handle_27e30 handle; char pad0e0[0x108 - 0xe0]; Item_27e30* excluded; };
struct Root_27e30 { void* FUN_00233580(const char* path); };
struct Context { char pad[0x5c]; Root_27e30* root; };
struct Manager_27e30 { Context* FUN_000240b0(void* key); };
extern void* DAT_0048e060;
extern Manager_27e30* DAT_004e5af8;
extern char DAT_0048e090;
extern char DAT_0048e0ac;
extern Item_27e30* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
struct Target_27e30 {
 Object* FUN_00024280(Key_27e30 key);
 bool FUN_00027e30(const char* name, const char* path);
};
bool Target_27e30::FUN_00027e30(const char* name, const char* path) {
 if (!path) return false;
 Key_27e30 key = FUN_002672f0(name,0,0);
 Object* object = FUN_00024280(key);
 if (!object) return false;
 Handle_27e30* handle = &object->handle;
 if (!handle) return false;
 Item_27e30* item = handle->item;
 if (!item) return false;
 if (!handle->FUN_00231ee0()) return false;
 if (item == object->excluded) return false;
 if (path[0] == '/') {
 Context* context = DAT_004e5af8->FUN_000240b0(DAT_0048e060);
 void* found = context->root->FUN_00233580(path);
 if (!found) return false;
 Item_27e30* result = FUN_00344e74(found,0,&DAT_0048e090,&DAT_0048e0ac,0);
 if (!result) return false;
 return result == item;
 }
 Key_27e30 other = FUN_0027b020(path);
 return item->low == (unsigned)other && item->high == (unsigned)(other >> 32);
}
