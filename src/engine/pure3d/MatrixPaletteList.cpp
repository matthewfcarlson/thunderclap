// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002e1920..0x002e1960 (kind game, layer engine, confidence medium), dominant class pure3d::MatrixPaletteList
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f7ad5fe2 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7ad5fe2 {} using namespace fn_f7ad5fe2;
namespace fn_f7ad5fe2 { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f7ad5fe2 {
extern void* hulk_at_0042fce4[];
} // namespace fn_f7ad5fe2
void operator delete(void*);
namespace fn_f7ad5fe2 {
class NonCopyable_2e1920 {
  public:
    void* vptr;
};
class MatrixPaletteList_2e1920 : public NonCopyable_2e1920 {
  public:
    char pad[4];
    void* m8;
    MatrixPaletteList_2e1920* f2(unsigned char flags);
};


// 0x002e1920 pure3d::MatrixPaletteList::vfunc_2 (53 B): matches/0x002e1920.cpp
// sym: ?f2@MatrixPaletteList_2e1920@fn_f7ad5fe2@@QAEPAV12@E@Z
MatrixPaletteList_2e1920* MatrixPaletteList_2e1920::f2(unsigned char flags) {
    vptr = hulk_at_0042fce4;
    _ReadWriteBarrier();
    if (m8)
        operator delete[](m8);
    vptr = (void**)DAT_003f6098;
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f7ad5fe2
