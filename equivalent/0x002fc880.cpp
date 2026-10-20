// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 14/16, incomplete)
// FUN_002fc880 @ 0x002fc880
struct Ref_2fc880 { virtual void AddRef() = 0; virtual void Release() = 0; };
struct Input_2fc880 { char pad[12]; int value; };
struct Wrapper_2fc880 : Ref_2fc880 { Wrapper_2fc880* FUN_00310080(Input_2fc880*, int, int); void FUN_0030ff80(int); };
extern void* __cdecl FUN_0008d690(unsigned int);
namespace physics {
struct PhysicsInstance {
 virtual void slot0();
 int field4;
 int field8;
 unsigned char enabled;
 char pad[3];
 Ref_2fc880* source;
 Wrapper_2fc880* wrapper;
 void FUN_002fc420();
 PhysicsInstance(Ref_2fc880*, Input_2fc880*);
};
}
physics::PhysicsInstance::PhysicsInstance(Ref_2fc880* input, Input_2fc880* data) {
 field4=0;
 enabled=1;
 source=0;
 wrapper=0;
 Ref_2fc880* old=source;
 if(old!=input){ source=input; if(input) input->AddRef(); if(old) old->Release(); }
 if(data){
  Wrapper_2fc880* object=(Wrapper_2fc880*)FUN_0008d690(32);
  if(object) object=object->FUN_00310080(data,2,data->value);
  Wrapper_2fc880* previous=wrapper;
  if(previous!=object){ wrapper=object; if(object) object->AddRef(); if(previous) previous->Release(); }
  wrapper->AddRef();
  wrapper->FUN_0030ff80(1);
 }
 FUN_002fc420();
}