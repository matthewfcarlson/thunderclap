// STATUS: equivalent (tools/equiv.py level 3: 10484 inputs, branch coverage 6/6)
// CTriggerVolume::vfunc_13 @ 0x001fb5a0
// cl-flags: /GS
#include "decls/address.h"
struct Input_1fb5a0 { char pad[8]; unsigned a,b; unsigned *value; unsigned FUN_00036d00(); };
struct Packet_1fb5a0 { unsigned type; char text[64]; char rest[628]; void FUN_001d1630(); };
struct Message_1fb5a0 { char data[84]; void FUN_001caf80(const char*,unsigned); };
struct Manager_1fb5a0 { void FUN_001d3b00(const char*,Packet_1fb5a0); };
struct Receiver_1fb5a0 { void FUN_001cbc20(Message_1fb5a0*); };
struct World { char pad[48]; Receiver_1fb5a0* receiver; };
extern Manager_1fb5a0* __cdecl FUN_001d4c90();
extern int __cdecl _sprintf(char*,const char*,...);
extern int __cdecl FUN_000964a0(char*,unsigned,const char*,...);
struct CTriggerVolume { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(unsigned,unsigned,int); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(Input_1fb5a0*); char pad[140]; char name[1]; };
void CTriggerVolume::vfunc_13(Input_1fb5a0* input) {
 vfunc_9(input->a,input->b,1);
 Manager_1fb5a0* manager=FUN_001d4c90();
 if(manager) {
 char eventName[256]; _sprintf(eventName,"%s_OnEnter",name);
 Packet_1fb5a0 packet; packet.FUN_001d1630(); packet.type=1;
 unsigned id=input->FUN_00036d00(); FUN_000964a0(packet.text,64,"%s",id);
 manager->FUN_001d3b00(eventName,packet);
 if(DAT_004dd700 && DAT_004dd700->receiver) {
 Receiver_1fb5a0* r=DAT_004dd700->receiver;
 Message_1fb5a0 message; message.FUN_001caf80(name,*input->value); r->FUN_001cbc20(&message);
 }
 }
}