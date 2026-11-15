// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070620..0x00072590 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x000719a0 FUN_000719a0 (213 B): equivalent/0x000719a0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_000719a0 @295a117fcdbc @w33cadea3833c
#include "gen/owners.h"
#include "decls/data/game/global.h"
namespace fn_fb4a3d99 {} using namespace fn_fb4a3d99;
namespace fn_fb4a3d99 {
// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 8/8)
// FUN_000719a0 @ 0x000719a0

void* __cdecl FUN_0008d690(unsigned);
bool FUN_00068580(void*, int); /* (unb4) as defined; address taken only */
bool FUN_00068590(void*, int); /* (unb4) as defined; address taken only */
bool FUN_000685a0(void*, int); /* (unb4) as defined; address taken only */

} // namespace fn_fb4a3d99
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_fb4a3d99 {

struct Base_719a0 {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 unsigned tail;
 void FUN_00234960(const char*);
};
class CInvincibleTrack;
namespace fight {
template<class T> struct ParamFloatConstRange : Base_719a0 {
 virtual void slot0();
};
}
void __cdecl FUN_002347b0(unsigned*, Base_719a0**, int);
extern "C" void __cdecl FUN_000719a0() {
 if (!DAT_004dcf8c) {
 Base_719a0* list[3];
 const char* names[3] = {"timeBegin", "timeEnd", "extensionTime"};
 void (__cdecl *callbacks[3])() = {(void (*)())FUN_00068580,(void (*)())FUN_00068590,(void (*)())FUN_000685a0};
 for (int i=0;i<3;++i) {
  Base_719a0* p = (Base_719a0*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CInvincibleTrack>));
  if(p) {
   p->FUN_00234960(names[i]);
   new(p) fight::ParamFloatConstRange<CInvincibleTrack>;
   p->callback=callbacks[i];
  }
  list[i]=p;
 }
 FUN_002347b0(&DAT_004dcf88,list,3);
 }
 ++DAT_004dcf8c;
}
} // namespace fn_fb4a3d99

