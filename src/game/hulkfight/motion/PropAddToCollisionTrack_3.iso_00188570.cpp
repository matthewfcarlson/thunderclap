// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00187340..0x00188ab0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAddToCollisionTrack
#include "tree_prelude.h"


// 0x00188570 FUN_00188570 (213 B): equivalent/0x00188570.cpp [isolated: helper definitions (2 out-of-line function bodies); compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00188570
#include "gen/owners.h"
#include "decls/data/game/hulkfight/motion.h"
namespace fn_f99e8f02 {} using namespace fn_f99e8f02;
namespace fn_f99e8f02 {
// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 8/8)
// FUN_00188570 @ 0x00188570

void* __cdecl FUN_0008d690(unsigned);
void __cdecl SetTimeBegin_00180390();
void __cdecl SetAttachmentIndex_001803b0();
void __cdecl SetMissiles_001803d0();

} // namespace fn_f99e8f02
HULK_NATIVE_INLINE void* operator new(size_t, void* p) { return p; }
namespace fn_f99e8f02 {

namespace hulkfight { namespace motion { class PropAddToMissileCountTrack; } }
struct ParamBase_188570 {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 unsigned extra;
 void FUN_00234960(const char*);
 void FUN_002348e0(const char*);
};
namespace fight {
 template<class T> struct ParamFloatConstRange: ParamBase_188570 { virtual void slot0(); };
 template<class T> struct ParamIntConstRange: ParamBase_188570 { virtual void slot0(); };
}
void __cdecl FUN_002347b0(unsigned*, ParamBase_188570**, int);
extern "C" void __cdecl FUN_00188570() {
 if (!DAT_004e14d4) {
  ParamBase_188570* params[3];
  ParamBase_188570* p=(ParamBase_188570*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::motion::PropAddToMissileCountTrack>));
  if(p) { p->FUN_00234960("timeBegin"); new(p) fight::ParamFloatConstRange<hulkfight::motion::PropAddToMissileCountTrack>; p->callback=SetTimeBegin_00180390; }
  params[0]=p;
  p=(ParamBase_188570*)FUN_0008d690((int)sizeof(fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>));
  if(p) { p->FUN_002348e0("attachmentIndex"); new(p) fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>; p->callback=SetAttachmentIndex_001803b0; }
  params[1]=p;
  p=(ParamBase_188570*)FUN_0008d690((int)sizeof(fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>));
  if(p) { p->FUN_002348e0("missiles"); new(p) fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>; p->callback=SetMissiles_001803d0; }
  params[2]=p;
  FUN_002347b0(&DAT_004e14d0,params,3);
 }
 ++DAT_004e14d4;
}
} // namespace fn_f99e8f02

