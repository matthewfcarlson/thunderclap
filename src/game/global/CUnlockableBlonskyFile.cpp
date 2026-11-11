// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000933e0..0x00093430 (kind game, layer game, confidence medium), dominant class CUnlockableBlonskyFile
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f3a656db {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3a656db {} using namespace fn_f3a656db;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3a656db {
extern "C" void Free1(void* p);
extern "C" void Free2(void* p);
class Helper_933e0 {
  public:
    void F();
};
class CUnlockableBlonskyFile {
  public:
    void* vfunc_0(unsigned char f);
};


// 0x000933e0 CUnlockableBlonskyFile::vfunc_0 (76 B): matches/0x000933e0.cpp
// sym: ?vfunc_0@CUnlockableBlonskyFile@fn_f3a656db@@QAEPAXE@Z
void* CUnlockableBlonskyFile::vfunc_0(unsigned char f) {
    char* s = (char*)this;
    *(hulk_intptr*)s = ((hulk_intptr)DAT_004044a4);
    ((Helper_933e0*)(s + 0x20))->F();
    void* p = *(void**)(s + 0x18);
    *(hulk_intptr*)s = ((hulk_intptr)DAT_0040449c);
    if (p) {
        Free1(p);
        *(void**)(s + 0x18) = 0;
    }
    ((Helper_933e0*)(s + 0x10))->F();
    if (f & 1)
        Free2(s);
    return this;
}

} // namespace fn_f3a656db
