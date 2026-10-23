// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_000d4620 @ 0x000d4620
#include "decls/data/game/global.h"

extern "C" char* __cdecl strncpy(char*,const char*,unsigned int);
struct Lookup_d4620 { int FUN_000f7d30(const char*); const char* FUN_000f7220(int); };
extern void __cdecl FUN_000fb690(char*,const char*,int);
extern void __cdecl FUN_000fc020(char*,int,const char*,int);
extern int __cdecl FUN_00294b80(const char*);
struct Slot_d4620 { char text[256]; int value; int zero; float duration; };
struct Object { char pad0[12]; Lookup_d4620* lookup; char pad1[0x47c]; Slot_d4620 slots[3]; char pad2[0x5c]; unsigned char enabled; void FUN_000d4620(int,const char*,int,int,float); };
void Object::FUN_000d4620(int index,const char* name,int mode,int value,float duration) {
 if (!enabled || index<0 || index>=3 || !name) return;
 strncpy(((char*)&DAT_004de000),name,255);
 DAT_004de0ff=0;
 int id=lookup->FUN_000f7d30(((char*)&DAT_004de000));
 if(id==-1) return;
 const char* source=lookup->FUN_000f7220(id);
 Slot_d4620& slot=slots[index];
 if(mode<0) FUN_000fb690(slot.text,source,128);
 else FUN_000fc020(slot.text,128,source,mode);
 if(FUN_00294b80(slot.text)>127) return;
 slot.value=value;
 slot.zero=0;
 slot.duration=duration<0.0f ? 3.0f : duration;
}
