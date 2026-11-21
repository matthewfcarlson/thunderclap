// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00106550..0x001065b0 (kind game, layer game, confidence medium), dominant class CPatrolPath
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/content.h"   // (nat2, D134) content::LoadObject's operator delete
#define TREE_TU_BEGIN namespace fn_f9481d31 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9481d31 {} using namespace fn_f9481d31;
void __cdecl operator delete[](void* p);   // (x64t21, D115) the game's 0x0008d340
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f9481d31 {
extern "C" char DAT_0040d564[];
class CPatrolPath {
  public:
    virtual void a();
    virtual void b();
    virtual CPatrolPath* vfunc_2(unsigned char);
    virtual void d();
    virtual void e();
    char pad[12];
    void* field10;
    int field14;
    void InitMember_0027afd0();
};


// 0x00106550 CPatrolPath::vfunc_2 (57 B): matches/0x00106550.cpp
// sym: ?vfunc_2@CPatrolPath@fn_f9481d31@@UAEPAV12@E@Z
CPatrolPath* CPatrolPath::vfunc_2(unsigned char flag) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0040d564);
    ::operator delete[](field10);
    this->field14 = 0;
    this->InitMember_0027afd0();
    if (flag & 1)
        ::content::LoadObject::operator delete(this);
    return this;
}

} // namespace fn_f9481d31
