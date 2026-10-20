// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 10/10)
// FUN_00131b90 @ 0x00131b90
#include "decls/data/game/hulkfight.h"

void* __cdecl FUN_0008d690(unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void __cdecl FUN_0012e180();
void __cdecl FUN_0012e190();
void __cdecl FUN_0012edf0();
void __cdecl FUN_0012ee50();
namespace hulkfight { class DebugPrintTrack; }
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char data[12];
 void (__cdecl *callback)();
 unsigned int tail;
 void FUN_00234960(const char*);
};
template<class T> struct ParamString {
 virtual void slot0();
 char data[12];
 void (__cdecl *callback)();
 unsigned int tail;
 void FUN_002349e0(const char*);
};
}
void __cdecl FUN_002347b0(void*, void**, int);
void __cdecl target() {
 if (DAT_004e0e98 == 0) {
 void* entries[4];
 typedef fight::ParamFloatConstRange<hulkfight::DebugPrintTrack> Float;
 typedef fight::ParamString<hulkfight::DebugPrintTrack> String;
 Float* a=(Float*)FUN_0008d690(24);
 if(a) { a->FUN_00234960("timeBegin"); new(a) Float; a->callback=FUN_0012e180; } entries[0]=a;
 Float* b=(Float*)FUN_0008d690(24);
 if(b) { b->FUN_00234960("timeEnd"); new(b) Float; b->callback=FUN_0012e190; } entries[1]=b;
 String* c=(String*)FUN_0008d690(24);
 if(c) { c->FUN_002349e0("text"); new(c) String; c->callback=FUN_0012edf0; } entries[2]=c;
 String* d=(String*)FUN_0008d690(24);
 if(d) { d->FUN_002349e0("channel"); new(d) String; d->callback=FUN_0012ee50; } entries[3]=d;
 FUN_002347b0(&DAT_004e0e94, entries, 4);
 }
 ++DAT_004e0e98;
}