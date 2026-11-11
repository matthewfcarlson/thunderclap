// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00106550..0x001065b0 (kind game, layer game, confidence medium), dominant class CPatrolPath
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f9481d31 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9481d31 {} using namespace fn_f9481d31;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f9481d31 {
extern "C" char DAT_0040d564[];
void DeleteThing_00263f30(void*);
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
    ReleaseThing(field10);
    this->field14 = 0;
    this->InitMember_0027afd0();
    if (flag & 1)
        DeleteThing_00263f30(this);
    return this;
}

} // namespace fn_f9481d31
