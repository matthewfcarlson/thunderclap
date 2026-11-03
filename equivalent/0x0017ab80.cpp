// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 10/10)
// FUN_0017ab80 @ 0x0017ab80
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) { return p; }
extern "C" void* __cdecl FUN_0008d690(unsigned int);
void FUN_0016f930(); void FUN_0016f960(); void FUN_0016f9a0(); void FUN_0016f9d0();
namespace hulkfight { namespace motion { class TeleportRelativeTrack_17ab80; } }
struct BaseFloat_17ab80 { virtual void slot0(); char pad[12]; void (*callback)(); int tail;  };
struct BaseVector { virtual void slot0(); char pad[12]; void (*callback)(); int tail; void FUN_00234e50(const char*); };
namespace fight {
template<class T> struct ParamFloatConstRange_17ab80 : BaseFloat_17ab80 { virtual void slot0(); };
template<class T> struct ParamVector_17ab80 : BaseVector { virtual void slot0(); };
}
 
void __cdecl FUN_002347b0(int*, void**, int);
extern "C" void __cdecl FUN_0017ab80() {
 if (DAT_004e1394 == 0) {
 void* params[4];
 typedef fight::ParamFloatConstRange_17ab80<hulkfight::motion::TeleportRelativeTrack_17ab80> F;
 typedef fight::ParamVector_17ab80<hulkfight::motion::TeleportRelativeTrack_17ab80> V;
 F* a = (F*)FUN_0008d690(24);
 if(a) { ((fight::ParamValueFloat *)(BaseFloat_17ab80 *)a)->FUN_00234960("timeBegin"); new(a) F; a->callback=FUN_0016f930; } params[0]=a;
 V* b = (V*)FUN_0008d690(24);
 if(b) { b->FUN_00234e50("offset"); new(b) V; b->callback=FUN_0016f960; } params[1]=b;
 V* c = (V*)FUN_0008d690(24);
 if(c) { c->FUN_00234e50("minimum"); new(c) V; c->callback=FUN_0016f9a0; } params[2]=c;
 F* d = (F*)FUN_0008d690(24);
 if(d) { ((fight::ParamValueFloat *)(BaseFloat_17ab80 *)d)->FUN_00234960("traceWidth"); new(d) F; d->callback=FUN_0016f9d0; } params[3]=d;
 FUN_002347b0(&DAT_004e1390, params, 4);
 }
 ++DAT_004e1394;
}
