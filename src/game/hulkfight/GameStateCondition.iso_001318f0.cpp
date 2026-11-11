// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012dfe0..0x00132e00 (kind game, layer game, confidence high), dominant class hulkfight::GameStateCondition
#include "tree_prelude.h"


// 0x001318f0 FUN_001318f0 (256 B): equivalent/0x001318f0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: ?FUN_001318f0@fn_f62c01b9@@YAXXZ
#include "gen/owners.h"
#include "decls/data/game/hulkfight.h"
namespace fn_f62c01b9 {} using namespace fn_f62c01b9;
namespace fn_f62c01b9 {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 10/10)
// FUN_001318f0 @ 0x001318f0


} // namespace fn_f62c01b9
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f62c01b9 {

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0012e0c0();
void __cdecl FUN_0012e9e0();
void __cdecl FUN_0012ea40();
void __cdecl FUN_0012eaa0();
struct FUN_00234960 {
 FUN_00234960(const char* = "timeBegin");
 virtual void baseSlot();
 char data[12];
 void (__cdecl *callback)();
 char tail[4];
};
struct FUN_002349e0 {
 FUN_002349e0(const char*);
 virtual void baseSlot();
 char data[12];
 void (__cdecl *callback)();
 char tail[4];
};
namespace hulkfight { class NISSoundTrack; }
namespace fight {
template<class T> struct ParamFloatConstRange : FUN_00234960 { virtual void baseSlot(); };
template<class T> struct ParamString : FUN_002349e0 { virtual void baseSlot(); ParamString(const char* s) : FUN_002349e0(s) {} };
}
void __cdecl FUN_002347b0(unsigned int*, void**, int);
void FUN_001318f0() {
 if (!DAT_004e0e88) {
 void* params[4];
 void* mem=FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::NISSoundTrack>));
 fight::ParamFloatConstRange<hulkfight::NISSoundTrack>* a = mem ? new(mem) fight::ParamFloatConstRange<hulkfight::NISSoundTrack> : 0;
 params[0]=a;
 if(a) a->callback=FUN_0012e0c0;
 mem=FUN_0008d690((int)sizeof(fight::ParamString<hulkfight::NISSoundTrack>));
 fight::ParamString<hulkfight::NISSoundTrack>* b = mem ? new(mem) fight::ParamString<hulkfight::NISSoundTrack>("sound") : 0;
 params[1]=b;
 if(b) b->callback=FUN_0012e9e0;
 mem=FUN_0008d690((int)sizeof(fight::ParamString<hulkfight::NISSoundTrack>));
 fight::ParamString<hulkfight::NISSoundTrack>* c = mem ? new(mem) fight::ParamString<hulkfight::NISSoundTrack>("obj") : 0;
 params[2]=c;
 if(c) c->callback=FUN_0012ea40;
 mem=FUN_0008d690((int)sizeof(fight::ParamString<hulkfight::NISSoundTrack>));
 fight::ParamString<hulkfight::NISSoundTrack>* d = mem ? new(mem) fight::ParamString<hulkfight::NISSoundTrack>("instance") : 0;
 params[3]=d;
 if(d) d->callback=FUN_0012eaa0;
 FUN_002347b0(&DAT_004e0e84,params,4);
 }
 ++DAT_004e0e88;
}
} // namespace fn_f62c01b9

