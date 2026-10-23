// STATUS: equivalent (tools/equiv.py level 3: 10508 inputs, branch coverage 6/6)
// CTriggerVolume::vfunc_14 @ 0x001fb6a0
// cl-flags: /GS
#include "decls/address.h"
struct EventData_1fb6a0 { int words[174]; void FUN_001d1630(); };
struct Key_1fb6a0 { char data[84]; void FUN_001cb050(const char*, int); };
struct Input_1fb6a0 { char pad[8]; int a,b; int* value; int FUN_00036d00(); };
struct Manager_1fb6a0 { void FUN_001d3b00(const char*, EventData_1fb6a0); };
struct Receiver_1fb6a0 { void FUN_001cbc20(Key_1fb6a0*); };
struct World { char pad[48]; Receiver_1fb6a0* receiver; };
extern Manager_1fb6a0* __cdecl FUN_001d4c90();
extern int __cdecl _sprintf(char*, const char*, ...);
extern void __cdecl FUN_000964a0(char*, int, const char*, int);
struct CTriggerVolume {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(int,int,int); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(Input_1fb6a0*); virtual void vfunc_15();
char pad[140]; char name[1];
};
void CTriggerVolume::vfunc_14(Input_1fb6a0* input) {
vfunc_9(input->a,input->b,0);
Manager_1fb6a0* manager=FUN_001d4c90();
if(manager) {
const char* n=name;
char eventName[256];
_sprintf(eventName,"%s_OnExit",n);
EventData_1fb6a0 data;
data.FUN_001d1630();
data.words[0]=1;
int text=input->FUN_00036d00();
FUN_000964a0((char*)&data.words[1],64,"%s",text);
manager->FUN_001d3b00(eventName,data);
if(DAT_004dd700 && DAT_004dd700->receiver) {
Receiver_1fb6a0* receiver=DAT_004dd700->receiver;
Key_1fb6a0 key;
key.FUN_001cb050(n,*input->value);
receiver->FUN_001cbc20(&key);
}
}
}