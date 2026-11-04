// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_0017ae00 @ 0x0017ae00
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void SetTimeBegin_0016fa60(); void SetTimeEnd_0016fa70(); void SetClearOnBegin_0016fa90();
struct FloatBase_17ae00 { virtual void slot0(); char padding[12]; void (*callback)(); int tail;  };
struct BoolBase { virtual void slot0(); char padding[12]; void (*callback)(); int tail;  };
namespace hulkfight { namespace motion { class ChargeClearTrack_17ae00; } }
namespace fight {
 template<class T> struct ParamFloatConstRange_17ae00 : FloatBase_17ae00 { virtual void slot0(); };
 template<class T> struct ParamBool_17ae00 : BoolBase { virtual void slot0(); };
}
void __cdecl FUN_002347b0(int*, void**, int);
void __cdecl target() {
 if (!DAT_004e13ac) {
 void* params[3];
 typedef fight::ParamFloatConstRange_17ae00<hulkfight::motion::ChargeClearTrack_17ae00> FloatParam;
 typedef fight::ParamBool_17ae00<hulkfight::motion::ChargeClearTrack_17ae00> BoolParam;
 FloatParam* a = (FloatParam*)FUN_0008d690(24);
 if(a) { ((fight::ParamValueFloat *)(FloatBase_17ae00 *)a)->FUN_00234960("timeBegin"); a = new(a) FloatParam; a->callback = SetTimeBegin_0016fa60; }
 params[0] = a;
 FloatParam* b = (FloatParam*)FUN_0008d690(24);
 if(b) { ((fight::ParamValueFloat *)(FloatBase_17ae00 *)b)->FUN_00234960("timeEnd"); b = new(b) FloatParam; b->callback = SetTimeEnd_0016fa70; }
 params[1] = b;
 BoolParam* c = (BoolParam*)FUN_0008d690(24);
 if(c) { ((fight::ParamValueBool *)(BoolBase *)c)->FUN_00234860("clearOnBegin"); c = new(c) BoolParam; c->callback = SetClearOnBegin_0016fa90; }
 params[2] = c;
 FUN_002347b0(&DAT_004e13a8,params,3);
 }
 ++DAT_004e13ac;
}
