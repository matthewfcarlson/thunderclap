// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00187340..0x00188ab0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAddToCollisionTrack
#include "tree_prelude.h"


// 0x00188040 FUN_00188040 (256 B): equivalent/0x00188040.cpp [isolated: helper definitions (2 out-of-line function bodies); compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00188040 @1945a1ef9058 @w56326cce49d2
#include "gen/owners.h"
#include "decls/data/game/hulkfight/motion.h"
namespace fn_f79f8c40 {} using namespace fn_f79f8c40;
namespace fn_f79f8c40 {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 10/10)
// FUN_00188040 @ 0x00188040


} // namespace fn_f79f8c40
HULK_NATIVE_INLINE void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f79f8c40 {

extern void* __cdecl FUN_0008d690(unsigned int);
extern char SetTimeBegin_0017f890(void*, int); /* (unb5) as defined; address taken only */
extern bool SetAttachmentIndex_0017f8b0(void*, int); /* (unb5) as defined; address taken only */
extern char SetDamage_0017f8d0(void*, int); /* (unb5) as defined; address taken only */
extern char SetDamageMax_0017f8f0(void*, int); /* (unb5) as defined; address taken only */
namespace hulkfight { namespace motion { class GrapplePropDamageTrack; } }
struct ParamBase_188040 {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 unsigned int tail;
 void FUN_00234960(const char*);
 void FUN_002348e0(const char*);
};
namespace fight {
template<class T> struct ParamFloatConstRange : ParamBase_188040 { virtual void slot0(); };
template<class T> struct ParamIntConstRange : ParamBase_188040 { virtual void slot0(); };
}
extern void __cdecl FUN_002347b0(void*, ParamBase_188040**, int);
extern "C" void __cdecl FUN_00188040() {
 if (!DAT_004e1494) {
  ParamBase_188040* params[4];
  ParamBase_188040* p = (ParamBase_188040*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>));
  if(p) { p->FUN_00234960("timeBegin"); new(p) fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>; p->callback=(void (*)())SetTimeBegin_0017f890; }
  params[0]=p;
  p=(ParamBase_188040*)FUN_0008d690((int)sizeof(fight::ParamIntConstRange<hulkfight::motion::GrapplePropDamageTrack>));
  if(p) { p->FUN_002348e0("attachmentIndex"); new(p) fight::ParamIntConstRange<hulkfight::motion::GrapplePropDamageTrack>; p->callback=(void (*)())SetAttachmentIndex_0017f8b0; }
  params[1]=p;
  p=(ParamBase_188040*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>));
  if(p) { p->FUN_00234960("damage"); new(p) fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>; p->callback=(void (*)())SetDamage_0017f8d0; }
  params[2]=p;
  p=(ParamBase_188040*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>));
  if(p) { p->FUN_00234960("damageMax"); new(p) fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>; p->callback=(void (*)())SetDamageMax_0017f8f0; }
  params[3]=p;
  FUN_002347b0(&DAT_004e1490,params,4);
 }
 ++DAT_004e1494;
}
} // namespace fn_f79f8c40

