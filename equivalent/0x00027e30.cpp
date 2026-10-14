// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 23/24, incomplete)
// FUN_00027e30 @ 0x00027e30
// Does the named pawn's current item match the item at `path` (or the item with that name hash)?
// Variant of 0x00027f00 that rejects the pawn's excluded item first.
typedef unsigned __int64 Key;
struct Item { char pad[8]; unsigned low; unsigned high; };
struct Handle { Item* item; bool FUN_00231ee0(); };
struct Object { char pad[0xdc]; Handle handle; char pad0e0[0x108 - 0xe0]; Item* excluded; };
struct Root { void* FUN_00233580(const char* path); };
struct Context { char pad[0x5c]; Root* root; };
struct Manager { Context* FUN_000240b0(void* key); };
extern void* DAT_0048e060;
extern Manager* DAT_004e5af8;
extern char DAT_0048e090;
extern char DAT_0048e0ac;
extern Key __cdecl FUN_002672f0(const char*, int, int);
extern Key __cdecl FUN_0027b020(const char*);
extern Item* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
struct Target {
 Object* FUN_00024280(Key key);
 bool FUN_00027e30(const char* name, const char* path);
};
bool Target::FUN_00027e30(const char* name, const char* path) {
 if (!path) return false;
 Key key = FUN_002672f0(name,0,0);
 Object* object = FUN_00024280(key);
 if (!object) return false;
 Handle* handle = &object->handle;
 if (!handle) return false;
 Item* item = handle->item;
 if (!item) return false;
 if (!handle->FUN_00231ee0()) return false;
 if (item == object->excluded) return false;
 if (path[0] == '/') {
 Context* context = DAT_004e5af8->FUN_000240b0(DAT_0048e060);
 void* found = context->root->FUN_00233580(path);
 if (!found) return false;
 Item* result = FUN_00344e74(found,0,&DAT_0048e090,&DAT_0048e0ac,0);
 if (!result) return false;
 return result == item;
 }
 Key other = FUN_0027b020(path);
 return item->low == (unsigned)other && item->high == (unsigned)(other >> 32);
}
