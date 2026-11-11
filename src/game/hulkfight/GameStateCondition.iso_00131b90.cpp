// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012dfe0..0x00132e00 (kind game, layer game, confidence high), dominant class hulkfight::GameStateCondition
#include "tree_prelude.h"


// 0x00131b90 FUN_00131b90 (256 B): equivalent/0x00131b90.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: ?target@fn_fa9ee2e9@@YAXXZ
#include "gen/owners.h"
#include "decls/data/game/hulkfight.h"
namespace fn_fa9ee2e9 {} using namespace fn_fa9ee2e9;
namespace fn_fa9ee2e9 {
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 10/10)
// FUN_00131b90 @ 0x00131b90

void* __cdecl FUN_0008d690(unsigned int);

} // namespace fn_fa9ee2e9
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_fa9ee2e9 {

void __cdecl SetTimeBegin_0012e180();
void __cdecl SetTimeEnd_0012e190();
void __cdecl FUN_0012edf0();
void __cdecl SetChannel_0012ee50();
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
 Float* a=(Float*)FUN_0008d690((int)sizeof(Float));
 if(a) { a->FUN_00234960("timeBegin"); new(a) Float; a->callback=SetTimeBegin_0012e180; } entries[0]=a;
 Float* b=(Float*)FUN_0008d690((int)sizeof(Float));
 if(b) { b->FUN_00234960("timeEnd"); new(b) Float; b->callback=SetTimeEnd_0012e190; } entries[1]=b;
 String* c=(String*)FUN_0008d690((int)sizeof(String));
 if(c) { c->FUN_002349e0("text"); new(c) String; c->callback=FUN_0012edf0; } entries[2]=c;
 String* d=(String*)FUN_0008d690((int)sizeof(String));
 if(d) { d->FUN_002349e0("channel"); new(d) String; d->callback=SetChannel_0012ee50; } entries[3]=d;
 FUN_002347b0(&DAT_004e0e94, entries, 4);
 }
 ++DAT_004e0e98;
}
} // namespace fn_fa9ee2e9

