// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 10/10)
// FUN_00131600 @ 0x00131600
#include "decls/data/game/hulkfight.h"

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0012e020(); void __cdecl FUN_0012e030(); void __cdecl FUN_0012e710(); void __cdecl FUN_0012e770();
namespace hulkfight { class LocationCondition; }
namespace fight {
template<class T> struct ParamEnumConstList { virtual void slot0(); char base[12]; int* values; int count; void (__cdecl *callback)(); int extra; void FUN_00234cc0(const char*); };
template<class T> struct ParamStringConstList { virtual void slot0(); char base[12]; void (__cdecl *callback)(); int extra; void FUN_00234af0(const char*); };
}
void __cdecl FUN_002347b0(int*,void**,int);
void __cdecl FUN_00131600() {
 if (DAT_004e0e70 == 0) {
 void* entries[4];
 typedef fight::ParamEnumConstList<hulkfight::LocationCondition> Enum;
 typedef fight::ParamStringConstList<hulkfight::LocationCondition> String;
 Enum* a = (Enum*)FUN_0008d690(32);
 if(a) { a->FUN_00234cc0("environmentCompare"); a->Enum::ParamEnumConstList(); a->values=((int*)&DAT_004a9bb4); a->count=3; a->callback=FUN_0012e020; }
 entries[0]=a;
 String* b=(String*)FUN_0008d690(24);
 if(b) { b->FUN_00234af0("environment"); b->String::ParamStringConstList(); b->callback=FUN_0012e710; }
 entries[1]=b;
 Enum* c=(Enum*)FUN_0008d690(32);
 if(c) { c->FUN_00234cc0("timeOfDayCompare"); c->Enum::ParamEnumConstList(); c->values=((int*)&DAT_004a9bb4); c->count=3; c->callback=FUN_0012e030; }
 entries[2]=c;
 String* d=(String*)FUN_0008d690(24);
 if(d) { d->FUN_00234af0("timeOfDay"); d->String::ParamStringConstList(); d->callback=FUN_0012e770; }
 entries[3]=d;
 FUN_002347b0(((int*)&DAT_004e0e6c),entries,4);
 }
 ++DAT_004e0e70;
}