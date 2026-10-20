// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 10/10)
// FUN_00187e00 @ 0x00187e00
#include "decls/data/game/unknown.h"

void* __cdecl FUN_0008d690(unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void __cdecl FUN_0017f6b0(); void __cdecl FUN_0017f6d0(); void __cdecl FUN_0017f6f0(); void __cdecl FUN_0017f710();
namespace hulkfight { namespace motion { class PropActorToPropTrack; } }
struct ParamBase_187e00 {
 virtual void slot0();
 char data[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_00234960(const char*);
 void FUN_002348e0(const char*);
 void FUN_00234860(const char*);
};
namespace fight {
 template<class T> struct ParamFloatConstRange : ParamBase_187e00 { virtual void slot0(); };
 template<class T> struct ParamIntConstRange : ParamBase_187e00 { virtual void slot0(); };
 template<class T> struct ParamBool : ParamBase_187e00 { virtual void slot0(); };
}
 
void __cdecl FUN_002347b0(void*, void**, int);
void __cdecl target() {
 if (DAT_004e146c == 0) {
 void* params[4];
 typedef fight::ParamFloatConstRange<hulkfight::motion::PropActorToPropTrack> FloatParam;
 typedef fight::ParamIntConstRange<hulkfight::motion::PropActorToPropTrack> IntParam;
 typedef fight::ParamBool<hulkfight::motion::PropActorToPropTrack> BoolParam;
 ParamBase_187e00* p = (ParamBase_187e00*)FUN_0008d690(24);
 if(p) { p->FUN_00234960("timeBegin"); new(p) FloatParam; p->callback=FUN_0017f6b0; }
 params[0]=p;
 p=(ParamBase_187e00*)FUN_0008d690(24);
 if(p) { p->FUN_002348e0("attachmentIndex"); new(p) IntParam; p->callback=FUN_0017f6d0; }
 params[1]=p;
 p=(ParamBase_187e00*)FUN_0008d690(24);
 if(p) { p->FUN_00234860("simulate"); new(p) BoolParam; p->callback=FUN_0017f6f0; }
 params[2]=p;
 p=(ParamBase_187e00*)FUN_0008d690(24);
 if(p) { p->FUN_00234860("atEnd"); new(p) BoolParam; p->callback=FUN_0017f710; }
 params[3]=p;
 FUN_002347b0(&DAT_004e1468,params,4);
 }
 ++DAT_004e146c;
}
