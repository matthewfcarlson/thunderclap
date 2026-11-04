// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 10/10)
// FUN_0019aca0 @ 0x0019aca0
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

extern "C" void* __cdecl FUN_0008d690(unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void __cdecl SetTimeBegin_001927d0();
void __cdecl SetTimeEnd_001927e0();
void __cdecl SetDecay_00192800();
void __cdecl SetDecayScaler_00192820();
struct Base_19aca0 {
 virtual void baseSlot();
 char padding[12];
 void (__cdecl *callback)();
 unsigned int tail;
};
namespace hulkfight { namespace motion { class AccuracyLatencyTrack_19aca0; } }
namespace fight {
template<class T> struct ParamFloatConstRange_19aca0 : Base_19aca0 {
 virtual void baseSlot();
};
}
typedef fight::ParamFloatConstRange_19aca0<hulkfight::motion::AccuracyLatencyTrack_19aca0> Param;
void __cdecl FUN_002347b0(void*, Param**, int);
void target() {
 if (DAT_004e1574 == 0) {
 Param* entries[4];
 void* p = FUN_0008d690(24);
 if(p) { ((fight::ParamValueFloat *)(Base_19aca0 *)(((Base_19aca0*)p)))->FUN_00234960("timeBegin"); entries[0] = new(p) Param; entries[0]->callback = SetTimeBegin_001927d0; } else entries[0]=0;
 p = FUN_0008d690(24);
 if(p) { ((fight::ParamValueFloat *)(Base_19aca0 *)(((Base_19aca0*)p)))->FUN_00234960("timeEnd"); entries[1] = new(p) Param; entries[1]->callback = SetTimeEnd_001927e0; } else entries[1]=0;
 p = FUN_0008d690(24);
 if(p) { ((fight::ParamValueFloat *)(Base_19aca0 *)(((Base_19aca0*)p)))->FUN_00234960("decay"); entries[2] = new(p) Param; entries[2]->callback = SetDecay_00192800; } else entries[2]=0;
 p = FUN_0008d690(24);
 if(p) { ((fight::ParamValueFloat *)(Base_19aca0 *)(((Base_19aca0*)p)))->FUN_00234960("decayScaler"); entries[3] = new(p) Param; entries[3]->callback = SetDecayScaler_00192820; } else entries[3]=0;
 FUN_002347b0(&DAT_004e1570, entries, 4);
 }
 ++DAT_004e1574;
}