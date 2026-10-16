// STATUS: equivalent (tools/equiv.py level 3: 2980 inputs, branch coverage 22/22)
// FUN_00042990 @ 0x00042990
#include "decls/address.h"
struct Object;
struct Flag_42990 { char pad[0x72]; unsigned char enabled; };
struct Link_42990 { Object* FUN_001d72e0(); };
struct Owner_42990 { char pad[0x128]; Link_42990* link; };
struct Object { char pad[8]; Owner_42990* owner; int kind; char pad2[0x64]; Flag_42990* flag; };
struct Local_42990 { unsigned int data[3]; };
void __cdecl FUN_00096a40(Object*, Local_42990*);
struct Renderer_42990 { void FUN_00025260(int,int,int); void FUN_000253c0(int); };
struct World { char pad[0x20]; Renderer_42990* renderer; };
struct Target_42990 {
 unsigned char FUN_0003e780(unsigned int, Local_42990*, unsigned int,unsigned int,unsigned int);
 unsigned char FUN_00042990(unsigned int,Object*,unsigned int,unsigned int,unsigned int);
};
unsigned char Target_42990::FUN_00042990(unsigned int a,Object* object,unsigned int c,unsigned int d,unsigned int e) {
 if (!object) return 0;
 Local_42990 local;
 FUN_00096a40(object,&local);
 if(object->flag) object->flag->enabled=0;
 if(object->kind==1 && object->owner->link) {
  Object* linked=object->owner->link->FUN_001d72e0();
  if(linked && linked->flag) linked->flag->enabled=0;
 }
 Renderer_42990* renderer=DAT_004dd700->renderer;
 renderer->FUN_00025260(0,0,0);
 renderer->FUN_000253c0(0);
 unsigned char result=FUN_0003e780(a,&local,c,d,e);
 if(object->flag) object->flag->enabled=1;
 if(object->kind==1 && object->owner->link) {
  Object* linked=object->owner->link->FUN_001d72e0();
  if(linked && linked->flag) linked->flag->enabled=1;
 }
 renderer->FUN_00025260(1,0,0);
 renderer->FUN_000253c0(1);
 return result;
}