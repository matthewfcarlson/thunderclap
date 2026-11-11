// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001fc600..0x001fc690 (kind game, layer game, confidence medium), dominant class CEncounterGenerator
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f2961f61 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f2961f61 {} using namespace fn_f2961f61;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f2961f61 {
class CEncounterGenerator_1fc600 {
  public:
    void Destroy();
};
class CEncounterGenerator {
  public:
    virtual void A();
    virtual void B();
    virtual CEncounterGenerator* vfunc_2(unsigned char);
    virtual void D();
    virtual void E();
};
extern void BaseDestroy(void*);
extern void BaseDestroyVec(void*);


// 0x001fc600 CEncounterGenerator::vfunc_2 (115 B): matches/0x001fc600.cpp
// sym: ?vfunc_2@CEncounterGenerator@fn_f2961f61@@UAEPAV12@E@Z
CEncounterGenerator* CEncounterGenerator::vfunc_2(unsigned char flags) {
    if (flags & 2) {
        char* base = (char*)this - 4;
        int n = *(int*)base;
        char* end = (char*)this + n * 0xc70;
        int test = n - 1;
        if (test >= 0) {
            int i = test + 1;
            do {
                end -= 0xc70;
                ((CEncounterGenerator_1fc600*)end)->Destroy();
                --i;
            } while (i != 0);
        }
        if (flags & 1)
            BaseDestroyVec(base);
        return (CEncounterGenerator*)base;
    }
    ((CEncounterGenerator_1fc600*)this)->Destroy();
    if (flags & 1)
        BaseDestroy(this);
    return this;
}

} // namespace fn_f2961f61
