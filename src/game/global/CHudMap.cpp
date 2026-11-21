// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000c9700..0x000c9720 (kind game, layer game, confidence medium), dominant class CHudMap
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f8a7a553 {
#define TREE_TU_END }
namespace fn_f8a7a553 {} using namespace fn_f8a7a553;
#include "game/global.h"


// 0x000c9700 CHudMap::vfunc_2 (30 B): matches/0x000c9700.cpp
// sym: ?vfunc_2@CHudMap_c9700@fn_000c9700@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `CHudMap::~CHudMap() {}` stood for it, which natively defines no function for
// the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's body 0x000c87a0, then
// (flags & 1) content::LoadObject::operator delete.
namespace fn_000c9700 {
struct CHudMap_c9700 {
    void FUN_000c87a0();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* CHudMap_c9700::vfunc_2(unsigned int flags) {
    FUN_000c87a0();
    if (flags & 1)
        ::content::LoadObject::operator delete(this);
    return this;
}
} // namespace fn_000c9700
// (x64t21) the destructor itself, which other objects' code references:
CHudMap::~CHudMap() {}

