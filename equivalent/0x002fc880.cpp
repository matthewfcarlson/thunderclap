// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 14/16, incomplete)
// FUN_002fc880 @ 0x002fc880
struct Ref { virtual void AddRef() = 0; virtual void Release() = 0; };
struct Input { char pad[12]; int value; };
struct Wrapper : Ref { Wrapper* FUN_00310080(Input*, int, int); void FUN_0030ff80(int); };
extern void* __cdecl FUN_0008d690(unsigned int);
namespace physics {
struct PhysicsInstance {
 virtual void slot0();
 int field4;
 int field8;
 unsigned char enabled;
 char pad[3];
 Ref* source;
 Wrapper* wrapper;
 void FUN_002fc420();
 PhysicsInstance(Ref*, Input*);
};
}
physics::PhysicsInstance::PhysicsInstance(Ref* input, Input* data) {
 field4=0;
 enabled=1;
 source=0;
 wrapper=0;
 Ref* old=source;
 if(old!=input){ source=input; if(input) input->AddRef(); if(old) old->Release(); }
 if(data){
  Wrapper* object=(Wrapper*)FUN_0008d690(32);
  if(object) object=object->FUN_00310080(data,2,data->value);
  Wrapper* previous=wrapper;
  if(previous!=object){ wrapper=object; if(object) object->AddRef(); if(previous) previous->Release(); }
  wrapper->AddRef();
  wrapper->FUN_0030ff80(1);
 }
 FUN_002fc420();
}