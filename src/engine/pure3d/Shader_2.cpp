// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028f240..0x0028f280 (kind game, layer engine, confidence medium), dominant class pure3d::Shader
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f7efdb18 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7efdb18 {} using namespace fn_f7efdb18;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f7efdb18 {
extern void* hulk_at_0042cb44[];
} // namespace fn_f7efdb18
void operator delete(void*);
namespace fn_f7efdb18 {
class Ref_28f240 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_28f240 {
  public:
    void* vptr;
    void Fin_0027afd0();
};
class Shader_28f240 : public Entity_28f240 {
  public:
    char pad[12];
    Ref_28f240* m;
    Shader_28f240* f2(unsigned char flags);
};


// 0x0028f240 pure3d::Shader::vfunc_2 (57 B): matches/0x0028f240.cpp
// sym: ?f2@Shader_28f240@fn_f7efdb18@@QAEPAV12@E@Z
Shader_28f240* Shader_28f240::f2(unsigned char flags) {
    vptr = hulk_at_0042cb44;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_0027afd0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f7efdb18
