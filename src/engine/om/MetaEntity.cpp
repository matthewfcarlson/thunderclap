// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0025e680..0x0025e900 (kind game, layer engine, confidence high), dominant class om::MetaEntity
#include "tree_prelude.h"
#include "gen/om.h"
#define TREE_TU_BEGIN namespace fn_f87db03b {
#define TREE_TU_END }
namespace fn_f87db03b {} using namespace fn_f87db03b;
#include "engine/om.h"

// ---- declarations shared by the functions below
namespace fn_f87db03b {
class Entity {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1(void*, void*);
    virtual void vfunc_2();
    virtual Entity* vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual Entity* vfunc_8();
};
class MetaEntity : public Entity {
  public:
    virtual void vfunc_2();
    virtual int vfunc_3(void*);
};
typedef unsigned __int64 U64_25e6c0;
class FUN_00243310 {
  public:
    FUN_00243310(const U64_25e6c0*, const U64_25e6c0*, int, int, int);
    virtual void f();
};
class MetaEntityType : public FUN_00243310 {
  public:
    MetaEntityType(const U64_25e6c0*, const U64_25e6c0*, int, int, int);
    virtual void f();
};
class MetaEntity_25e6f0 {
  public:
    virtual void f();
    MetaEntity_25e6f0* construct(void*);
};
struct MetaEntity_nv_25e6f0 {
    void InitRestPose_00244ea0(void*);
};
class MetaEntity_25e710 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
    virtual int vfunc_6();
};


// 0x0025e680 om::MetaEntity::vfunc_3 (32 B): matches/0x0025e680.cpp
// sym: ?vfunc_3@MetaEntity@fn_f87db03b@@UAEHPAX@Z
int MetaEntity::vfunc_3(void* p) {
    Entity* a = this->vfunc_8();
    Entity* b = a->vfunc_3();
    return b->vfunc_1(p, this);
}

} // namespace fn_f87db03b

// 0x0025e6a0 om::MetaEntity::vfunc_5 (32 B): matches/0x0025e6a0.cpp [wrapped: conflict: MetaEntity]
// sym: ?vfunc_5@MetaEntity@fn_0025e6a0@@UAEXPAVNode@2@@Z
namespace fn_0025e6a0 {
class Node {
  public:
    virtual void a0();
    virtual void a1();
    virtual Node* a2(Node*, Node*);
    virtual Node* a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual Node* a8();
};
class Entity {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a6();
    virtual void a7();
    virtual void a8();
};
class MetaEntity : public Entity {
  public:
    virtual Node* a2(Node*, Node*);
    virtual Node* a3();
    virtual void a4();
    virtual void vfunc_5(Node*);
};
void MetaEntity::vfunc_5(Node* arg) {
    Node* p = ((Node*)this)->a8();
    Node* q = p->a3();
    q->a2(arg, (Node*)this);
}
} // namespace fn_0025e6a0

namespace fn_f87db03b {

// 0x0025e6c0 FUN_0025e6c0 (47 B): matches/0x0025e6c0.cpp
// sym: ??0MetaEntityType@fn_f87db03b@@QAE@PB_K0HHH@Z
// om::MetaEntityType's constructor: om::EntityType's (0x00243310), named by its address for the native links.
MetaEntityType::MetaEntityType(const U64_25e6c0* a, const U64_25e6c0* b, int c, int d, int e)
    : FUN_00243310(a, b, c, d, e) {}


// 0x0025e6f0 FUN_0025e6f0 (25 B): matches/0x0025e6f0.cpp
// sym: ?construct@MetaEntity_25e6f0@fn_f87db03b@@QAEPAV12@PAX@Z
// Same code shape as 0x0022a5d0 (propagated; names are from that function)
MetaEntity_25e6f0* MetaEntity_25e6f0::construct(void* arg) {
    ((MetaEntity_nv_25e6f0*)(((om::MetaEntity*)(this))))->InitRestPose_00244ea0(arg);
    *(void**)this = &RestPoseVtable;
    return this;
}


// 0x0025e710 om::MetaEntity::vfunc_4 (5 B): matches/0x0025e710.cpp
// sym: ?vfunc_6@MetaEntity_25e710@fn_f87db03b@@UAEHXZ
// Same code shape as 0x0022a930 (propagated; names are from that function)
int MetaEntity_25e710::vfunc_6() {
    return v5();
}

} // namespace fn_f87db03b

// 0x0025e720 om::MetaEntityType::vfunc_1 (23 B): matches/0x0025e720.cpp [wrapped: conflict: MetaEntityType]
// sym: ?vfunc_0@MetaEntityType@fn_0025e720@@UAEXXZ
namespace fn_0025e720 {
// Same code shape as 0x0025e740 (propagated; names are from that function)
class Result_25e720 {
  public:
    void finish_0025fc80();
};
class EntityType {
  public:
    virtual void vfunc_0();
};
class MetaEntityType : public EntityType {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Result_25e720* vfunc_3();
};
void MetaEntityType::vfunc_0() {
    EntityType::vfunc_0();
    Result_25e720* r = vfunc_3();
    r->finish_0025fc80();
}
} // namespace fn_0025e720


// 0x0025e740 om::MetaEntityType::vfunc_0 (23 B): matches/0x0025e740.cpp [wrapped: conflict: MetaEntityType]
// sym: ?vfunc_0@MetaEntityType@fn_0025e740@@UAEXXZ
namespace fn_0025e740 {
class Result_25e740 {
  public:
    void finish_0025e850();
};
class EntityType {
  public:
    virtual void vfunc_0();
};
class MetaEntityType : public EntityType {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Result_25e740* vfunc_3();
};
void MetaEntityType::vfunc_0() {
    EntityType::vfunc_0();
    Result_25e740* r = vfunc_3();
    r->finish_0025e850();
}
} // namespace fn_0025e740


// 0x0025e760 om::MetaEntity::vfunc_2 (30 B): matches/0x0025e760.cpp
// sym: ??_GMetaEntity@om@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
om::MetaEntity::~MetaEntity() {}

namespace fn_f87db03b {

// 0x0025e850 FUN_0025e850 (1 B): matches/0x0025e850.cpp
// sym: ?FUN_0025e850@fn_f87db03b@@YAXXZ
void FUN_0025e850() {}

} // namespace fn_f87db03b
