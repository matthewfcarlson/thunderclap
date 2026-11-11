// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000935b0..0x00093600 (kind game, layer game, confidence medium), dominant class CUnlockableGallery
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fbee45d4 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fbee45d4 {} using namespace fn_fbee45d4;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fbee45d4 {
extern void* gG_935b0[];
extern void* gB_935b0[];
} // namespace fn_fbee45d4
void operator delete[](void*);
namespace fn_fbee45d4 {
struct S_935b0 {
    int a, b;
    void Fini();
};
class CUnlockableGallery_935b0 {
  public:
    void* vptr;
    char pad[0x10 - 4];
    S_935b0 s10;
    void* m18;
    char pad2[0xa8 - 0x1c];
    S_935b0 sa8;
    CUnlockableGallery_935b0* f0(unsigned char flags);
};


// 0x000935b0 CUnlockableGallery::vfunc_0 (79 B): matches/0x000935b0.cpp
// sym: ?f0@CUnlockableGallery_935b0@fn_fbee45d4@@QAEPAV12@E@Z
CUnlockableGallery_935b0* CUnlockableGallery_935b0::f0(unsigned char flags) {
    vptr = gG_935b0;
    sa8.Fini();
    void* p = m18;
    vptr = gB_935b0;
    if (p) {
        operator delete[](p);
        m18 = 0;
    }
    s10.Fini();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fbee45d4
