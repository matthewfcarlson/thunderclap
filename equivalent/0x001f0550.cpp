// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// CSoundCommand_StopTunableEvent::vfunc_1 @ 0x001f0550
#include "decls/address.h"
struct Key_1f0550 { unsigned int low, high; };
struct Entry_1f0550 { Key_1f0550 key; unsigned int id; char rest[28]; };
struct Event_1f0550 { char pad[128]; Entry_1f0550 entries[4]; };
struct Playing_1f0550 { void FUN_001f34a0(unsigned int*, int); };
struct Manager_1f0550 { Event_1f0550* FUN_001f31a0(unsigned int); Playing_1f0550* FUN_001f2f30(void*, unsigned int); };
struct Lookup_1f0550 { void* FUN_001e98b0(Key_1f0550*); };
struct SoundSystem_1f0550 { Manager_1f0550* manager; Lookup_1f0550* lookup; };
extern SoundSystem_1f0550* DAT_004e370c;
extern unsigned int __cdecl FUN_002673a0(int,int);
struct CSoundCommand_StopTunableEvent {
 virtual void vfunc_0();
 virtual void vfunc_1(unsigned int, unsigned int);
 char pad[12]; Key_1f0550 key; unsigned int id; float fade;
};
void CSoundCommand_StopTunableEvent::vfunc_1(unsigned int arg, unsigned int unused) {
 Event_1f0550* event = DAT_004e370c->manager->FUN_001f31a0(arg);
 if (!event) return;
 void* found = DAT_004e370c->lookup->FUN_001e98b0(&key);
 if (!found) return;
 unsigned int low=key.low, high=key.high;
 for (int i=0;i<4;++i) {
  Entry_1f0550& entry=event->entries[i];
  if (entry.key.low==low && entry.key.high==high && entry.id==id) {
   unsigned __int64 value=FUN_002672f0(0,0,0);
   entry.key.low=(unsigned int)value;
   entry.key.high=(unsigned int)(value>>32);
   entry.id=FUN_002673a0(0,0);
   break;
  }
 }
 Playing_1f0550* playing=DAT_004e370c->manager->FUN_001f2f30(found,arg);
 if (playing) {
  int duration=(int)fade;
  playing->FUN_001f34a0(&id,duration);
 }
}
