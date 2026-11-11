// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00199630..0x0019c050 (kind game, layer game, confidence high), dominant class hulkfight::motion::FireProjectileAction
#include "tree_prelude.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f67703b9 {
#define TREE_TU_END }
namespace fn_f67703b9 {} using namespace fn_f67703b9;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f67703b9 {
extern "C" void* __cdecl FUN_0008d690(unsigned int);
} // namespace fn_f67703b9
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f67703b9 {
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
} // namespace fn_f67703b9
namespace hulkfight { namespace motion {
class AccuracyLatencyTrack_19aca0;
} }
namespace fight {
template<class T> struct ParamFloatConstRange_19aca0 : Base_19aca0 {
 virtual void baseSlot();
};
}
namespace fn_f67703b9 {
typedef fight::ParamFloatConstRange_19aca0<hulkfight::motion::AccuracyLatencyTrack_19aca0> Param;
void __cdecl FUN_002347b0(void*, Param**, int);

} // namespace fn_f67703b9

// 0x0019aba0 FUN_0019aba0 (256 B): equivalent/0x0019aba0.cpp [wrapped: conflict: fight::ParamBranch; fight::ParamFloatConstRange]
// sym: ?FUN_0019aba0@fn_0019aba0@@YAXXZ @c539a1a254d2 @w64ace01d9e89
namespace fn_0019aba0 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 10/10)
// FUN_0019aba0 @ 0x0019aba0

typedef void (__cdecl *Callback_19aba0)();
void __cdecl SetTimeBegin_00192770();
void __cdecl SetTimeEnd_00192780();
void __cdecl SetArc_001927a0();
void __cdecl GetGiverBranch_001927c0();
extern "C" void* __cdecl FUN_0008d690(unsigned int);

namespace hulkfight { namespace motion { class MissilePunchTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char data[12];
 Callback_19aba0 callback;
 int tail;
 void FUN_00234960(const char*);
};
template<class T> struct ParamBranch {
 virtual void slot0();
 char data[12];
 Callback_19aba0 callback;
 int tail;
 void FUN_00235170(const char*);
};
}
typedef fight::ParamFloatConstRange<hulkfight::motion::MissilePunchTrack> FloatParam;
typedef fight::ParamBranch<hulkfight::motion::MissilePunchTrack> BranchParam;
void __cdecl FUN_002347b0(int*, void**, int);
void __cdecl FUN_0019aba0() {
 if (DAT_004e156c == 0) {
  void* params[4];
  FloatParam* p = (FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
  if(p) { p->FUN_00234960("timeBegin"); new(p) FloatParam; p->callback = SetTimeBegin_00192770; }
  params[0] = p;
  p = (FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
  if(p) { p->FUN_00234960("timeEnd"); new(p) FloatParam; p->callback = SetTimeEnd_00192780; }
  params[1] = p;
  p = (FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
  if(p) { p->FUN_00234960("arc"); new(p) FloatParam; p->callback = SetArc_001927a0; }
  params[2] = p;
  BranchParam* b = (BranchParam*)FUN_0008d690((int)sizeof(BranchParam));
  if(b) { b->FUN_00235170("giverBranch"); new(b) BranchParam; b->callback = GetGiverBranch_001927c0; }
  params[3] = b;
  FUN_002347b0(&DAT_004e1568, params, 4);
 }
 ++DAT_004e156c;
}
} // namespace fn_0019aba0

namespace fn_f67703b9 {

// 0x0019aca0 FUN_0019aca0 (256 B): equivalent/0x0019aca0.cpp
// sym: ?target@fn_f67703b9@@YAXXZ @0d9c99a43a38 @wf7a611d2719c
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 10/10)
// FUN_0019aca0 @ 0x0019aca0
void target() {
 if (DAT_004e1574 == 0) {
 Param* entries[4];
 void* p = FUN_0008d690((int)sizeof(Param));
 if(p) { ((fight::ParamValueFloat *)(Base_19aca0 *)(((Base_19aca0*)p)))->FUN_00234960("timeBegin"); entries[0] = new(p) Param; entries[0]->callback = SetTimeBegin_001927d0; } else entries[0]=0;
 p = FUN_0008d690((int)sizeof(Param));
 if(p) { ((fight::ParamValueFloat *)(Base_19aca0 *)(((Base_19aca0*)p)))->FUN_00234960("timeEnd"); entries[1] = new(p) Param; entries[1]->callback = SetTimeEnd_001927e0; } else entries[1]=0;
 p = FUN_0008d690((int)sizeof(Param));
 if(p) { ((fight::ParamValueFloat *)(Base_19aca0 *)(((Base_19aca0*)p)))->FUN_00234960("decay"); entries[2] = new(p) Param; entries[2]->callback = SetDecay_00192800; } else entries[2]=0;
 p = FUN_0008d690((int)sizeof(Param));
 if(p) { ((fight::ParamValueFloat *)(Base_19aca0 *)(((Base_19aca0*)p)))->FUN_00234960("decayScaler"); entries[3] = new(p) Param; entries[3]->callback = SetDecayScaler_00192820; } else entries[3]=0;
 FUN_002347b0(&DAT_004e1570, entries, 4);
 }
 ++DAT_004e1574;
}

} // namespace fn_f67703b9
