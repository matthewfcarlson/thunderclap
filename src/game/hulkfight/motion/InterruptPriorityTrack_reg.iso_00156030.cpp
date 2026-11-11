// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00154c00..0x00156e80 (kind game, layer game, confidence high), dominant class hulkfight::motion::InterruptPriorityTrack
#include "tree_prelude.h"


// 0x00156030 FUN_00156030 (213 B): equivalent/0x00156030.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00156030
#include "gen/owners.h"
#include "decls/data/game/hulkfight/motion.h"
namespace fn_fc84ab54 {} using namespace fn_fc84ab54;
namespace fn_fc84ab54 {
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 8/8)
// FUN_00156030 @ 0x00156030

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetTimeBegin_0014cce0();
void __cdecl SetTimeEnd_0014ccf0();
void __cdecl SetInterruptPriority_0014cd10();
void __cdecl FUN_002347b0(void*, void*, int);

} // namespace fn_fc84ab54
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_fc84ab54 {

namespace hulkfight { namespace motion { class InterruptPriorityTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_00234960(const char*);
};
template<class T> struct ParamIntConstRange {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_002348e0(const char*);
};
}
extern "C" void __cdecl FUN_00156030() {
 if (!DAT_004e1104) {
  void* params[3];
  typedef fight::ParamFloatConstRange<hulkfight::motion::InterruptPriorityTrack> FloatParam;
  typedef fight::ParamIntConstRange<hulkfight::motion::InterruptPriorityTrack> IntParam;
  FloatParam* a = (FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
  if(a) { a->FUN_00234960("timeBegin"); new(a) FloatParam; a->callback = SetTimeBegin_0014cce0; }
  params[0]=a;
  FloatParam* b = (FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
  if(b) { b->FUN_00234960("timeEnd"); new(b) FloatParam; b->callback = SetTimeEnd_0014ccf0; }
  params[1]=b;
  IntParam* c = (IntParam*)FUN_0008d690((int)sizeof(IntParam));
  if(c) { c->FUN_002348e0("interruptPriority"); new(c) IntParam; c->callback = SetInterruptPriority_0014cd10; }
  params[2]=c;
  FUN_002347b0(&DAT_004e1100,params,3);
 }
 ++DAT_004e1104;
}
} // namespace fn_fc84ab54

