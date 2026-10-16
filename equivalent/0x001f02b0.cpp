// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// CSoundCommand_PlayTunableEvent::vfunc_1 @ 0x001f02b0
#include "decls/address.h"
typedef unsigned long U32_1f02b0;
struct Key_1f02b0 { U32_1f02b0 low, high; };
struct Entry_1f02b0 { Key_1f02b0 key; U32_1f02b0 type; char pad[12]; U32_1f02b0 a,b,c; char tail[4]; };
struct Object { char pad[0x80]; Entry_1f02b0 entries[4]; };
struct Lookup_1f02b0 { Object* FUN_001f31a0(U32_1f02b0); };
struct Events_1f02b0 { int FUN_001e98b0(Key_1f02b0*); };
struct Manager_1f02b0 { Lookup_1f02b0* lookup; Events_1f02b0* events; };
extern Manager_1f02b0* DAT_004e370c;
struct CSoundCommand_PlayTunableEvent {
 virtual void vfunc_0();
 virtual void vfunc_1(U32_1f02b0, U32_1f02b0);
 char pad[12]; Key_1f02b0 key; U32_1f02b0 type; U32_1f02b0 a,b,c;
};
void CSoundCommand_PlayTunableEvent::vfunc_1(U32_1f02b0 arg, U32_1f02b0 unused) {
 if (!DAT_004e370c->events->FUN_001e98b0(&key)) return;
 Object* obj=DAT_004e370c->lookup->FUN_001f31a0(arg);
 if (!obj) return;
 for(int i=0;i<4;++i) {
  Entry_1f02b0& e=obj->entries[i];
  if(e.type==type && e.key.low==key.low && e.key.high==key.high) return;
 }
 for(int i=0;i<4;++i) {
  unsigned __int64 empty=FUN_002672f0(0,0,0);
  Entry_1f02b0& e=obj->entries[i];
  if(e.key.low==(U32_1f02b0)empty && e.key.high==(U32_1f02b0)(empty>>32)) {
   e.key.low=key.low; e.key.high=key.high; e.type=type;
   e.a=a; e.b=b; e.c=c; return;
  }
 }
}
