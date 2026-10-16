// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_000a74c0 @ 0x000a74c0
#include "decls/address.h"
typedef unsigned __int64 Key_a74c0;
extern void __cdecl FUN_00267830(char*, const char*, int);
struct Data_a74c0 { void FUN_00059a50(void*); };
struct Item_a74c0 { virtual void add(); virtual void release(); char pad[12]; Data_a74c0* data; const char* FUN_00036d00(); };
struct Manager_a74c0 { char pad[0x124]; Item_a74c0* fallback; Item_a74c0* FUN_00024280(Key_a74c0); };
struct Context { char pad[0x20]; Manager_a74c0* manager; };
struct Object { char pad0[0x1b8]; char value[0x18c]; unsigned char dirty; unsigned char isDefault; char pad1[10]; Item_a74c0* item; char name[64]; void FUN_000a62c0(Context*,Item_a74c0*); void target(Context*,const char*); };
void Object::target(Context* context,const char* requested) {
 Item_a74c0* selected=0;
 if(requested) {
  Manager_a74c0* manager=context->manager;
  Key_a74c0 key=FUN_002672f0(requested,0,0);
  selected=manager->FUN_00024280(key);
 } else if(!item) {
  Manager_a74c0* manager=context->manager;
  if(!name[0]) selected=manager->fallback;
  else { Key_a74c0 key=FUN_002672f0(name,0,0); selected=manager->FUN_00024280(key); }
  if(!selected) selected=manager->fallback;
 }
 if(selected) {
  selected->add();
  if(item) item->release();
  item=selected;
  isDefault=(selected==context->manager->fallback);
  FUN_00267830(name,selected->FUN_00036d00(),64);
  item->data->FUN_00059a50(value);
  dirty=0;
 }
 if(item) FUN_000a62c0(context,item);
}
