// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 10/10)
// FUN_0019aba0 @ 0x0019aba0
#include "decls/data/game/hulkfight/motion.h"

typedef void (__cdecl *Callback_19aba0)();
void __cdecl SetTimeBegin_00192770();
void __cdecl SetTimeEnd_00192780();
void __cdecl SetArc_001927a0();
void __cdecl GetGiverBranch_001927c0();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
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