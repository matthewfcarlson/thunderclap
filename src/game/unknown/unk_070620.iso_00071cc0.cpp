// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070620..0x00072590 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x00071cc0 FUN_00071cc0 (227 B): equivalent/0x00071cc0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00071cc0 @ecafb5a9b3d8 @w0723080e7583
#include "gen/owners.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
namespace fn_f6b538f9 {} using namespace fn_f6b538f9;
namespace fn_f6b538f9 {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_00071cc0 @ 0x00071cc0

void* __cdecl FUN_0008d690(unsigned int);

} // namespace fn_f6b538f9
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f6b538f9 {

void __cdecl SetTimeBegin_00068770();
void __cdecl SetTimeEnd_00068780();
void __cdecl SetHint_00068790();
class CCameraHintTrack;
namespace fight {
template<class T> struct ParamFloatConstRange { virtual void slot0(); char data[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00234960(const char*); };
template<class T> struct ParamEnumConstList { virtual void slot0(); char data[12]; unsigned int* list; int count; void (__cdecl *callback)(); char tail[4]; void FUN_00234cc0(const char*); };
}
void __cdecl FUN_002347b0(unsigned int*, void**, int);
extern "C" void FUN_00071cc0() {
 if (!DAT_004dcfb4) {
  void* entries[3];
  typedef fight::ParamFloatConstRange<CCameraHintTrack> FloatParam;
  typedef fight::ParamEnumConstList<CCameraHintTrack> EnumParam;
  FloatParam* a = (FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
  if (a) { a->FUN_00234960("timeBegin"); new (a) FloatParam; a->callback=SetTimeBegin_00068770; }
  entries[0]=a;
  FloatParam* b = (FloatParam*)FUN_0008d690((int)sizeof(FloatParam));
  if (b) { b->FUN_00234960("timeEnd"); new (b) FloatParam; b->callback=SetTimeEnd_00068780; }
  entries[1]=b;
  EnumParam* c = (EnumParam*)FUN_0008d690((int)sizeof(EnumParam));
  if (c) { c->FUN_00234cc0("hint"); new (c) EnumParam; c->list=((unsigned int*)&DAT_00496fb4); c->count=9; c->callback=SetHint_00068790; }
  entries[2]=c;
  FUN_002347b0(&DAT_004dcfb0, entries,3);
 }
 ++DAT_004dcfb4;
}
} // namespace fn_f6b538f9

