// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00111720..0x001133f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreWaitTrack
#include "tree_prelude.h"


// 0x001129a0 FUN_001129a0 (256 B): equivalent/0x001129a0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_001129a0 @15117c8710d6 @w112da235dda6
#include "gen/owners.h"
#include "decls/data/game/unknown.h"
namespace fn_f405969a {} using namespace fn_f405969a;
namespace fn_f405969a {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 10/10)
// FUN_001129a0 @ 0x001129a0

typedef void (__cdecl *Callback_1129a0)();
extern char SetTimeBegin_0010c4d0(void*, int); /* (unb5) as defined; address taken only */
extern bool SetTimeEnd_0010c4e0(void*, int); /* (unb5) as defined; address taken only */
extern void* GetText_0010c4f0(void*); /* (unb5) as defined; address taken only */
extern bool SetValue_0010c510(void*, int); /* (unb5) as defined; address taken only */
extern void* __cdecl FUN_0008d690(unsigned int);
extern void __cdecl FUN_002347b0(void*,void*,int);

} // namespace fn_f405969a
inline void* operator new(size_t, void* p) { return p; }
namespace fn_f405969a {

namespace hulkfight { namespace ai { class HulkActionTrack; } }
struct Base_1129a0 {
 virtual void slot0();
 char padding[12];
 Callback_1129a0 callback;
 int tail;
 void FUN_00234960(const char*);
 void FUN_00234a90(const char*);
};
namespace fight {
 template<class T> struct ParamFloatConstRange : Base_1129a0 { virtual void slot0(); };
 template<class T> struct ParamName : Base_1129a0 { virtual void slot0(); };
}
extern "C" void __cdecl FUN_001129a0() {
 if (DAT_004e0b7c == 0) {
  Base_1129a0* entries[4];
  Base_1129a0* p = (Base_1129a0*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>));
  if (p) { p->FUN_00234960("timeBegin"); new(p) fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>; p->callback=(void (*)())SetTimeBegin_0010c4d0; }
  entries[0]=p;
  p=(Base_1129a0*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>));
  if(p) { p->FUN_00234960("timeEnd"); new(p) fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>; p->callback=(void (*)())SetTimeEnd_0010c4e0; }
  entries[1]=p;
  p=(Base_1129a0*)FUN_0008d690((int)sizeof(fight::ParamName<hulkfight::ai::HulkActionTrack>));
  if(p) { p->FUN_00234a90("text"); new(p) fight::ParamName<hulkfight::ai::HulkActionTrack>; p->callback=(void (*)())GetText_0010c4f0; }
  entries[2]=p;
  p=(Base_1129a0*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>));
  if(p) { p->FUN_00234960("value"); new(p) fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>; p->callback=(void (*)())SetValue_0010c510; }
  entries[3]=p;
  FUN_002347b0(&DAT_004e0b78,entries,4);
 }
 ++DAT_004e0b7c;
}
} // namespace fn_f405969a

