// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 10/10)
// FUN_001318f0 @ 0x001318f0
#include "decls/data/game/hulkfight.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
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
 void* mem=FUN_0008d690(24);
 fight::ParamFloatConstRange<hulkfight::NISSoundTrack>* a = mem ? new(mem) fight::ParamFloatConstRange<hulkfight::NISSoundTrack> : 0;
 params[0]=a;
 if(a) a->callback=FUN_0012e0c0;
 mem=FUN_0008d690(24);
 fight::ParamString<hulkfight::NISSoundTrack>* b = mem ? new(mem) fight::ParamString<hulkfight::NISSoundTrack>("sound") : 0;
 params[1]=b;
 if(b) b->callback=FUN_0012e9e0;
 mem=FUN_0008d690(24);
 fight::ParamString<hulkfight::NISSoundTrack>* c = mem ? new(mem) fight::ParamString<hulkfight::NISSoundTrack>("obj") : 0;
 params[2]=c;
 if(c) c->callback=FUN_0012ea40;
 mem=FUN_0008d690(24);
 fight::ParamString<hulkfight::NISSoundTrack>* d = mem ? new(mem) fight::ParamString<hulkfight::NISSoundTrack>("instance") : 0;
 params[3]=d;
 if(d) d->callback=FUN_0012eaa0;
 FUN_002347b0(&DAT_004e0e84,params,4);
 }
 ++DAT_004e0e88;
}