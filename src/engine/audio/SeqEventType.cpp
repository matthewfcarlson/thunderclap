// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00260950..0x00260a40 (kind game, layer engine, confidence medium), dominant class audio::SeqEventType
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/records.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe02c6d2 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe02c6d2 {} using namespace fn_fe02c6d2;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fe02c6d2 {
void DestroySeq_0008d330(void*);
class Sub_260950 {
  public:
};
class Type {
  public:
    virtual void dtor(unsigned int);
    virtual void vfunc1();
    virtual Type* vfunc2(unsigned int);
    virtual void vfunc3();
};
class SeqEventType : public Type {
  public:
    char pad[0x54];
    Sub_260950 sub;
    void FUN_002580e0();
    SeqEventType* vfunc2(unsigned int flags);
};


// 0x00260950 audio::SeqEventType::vfunc_2 (74 B): matches/0x00260950.cpp
// sym: ?vfunc2@SeqEventType@fn_fe02c6d2@@UAEPAV12@I@Z
// data: gCount_260950 = DAT_004e7a18.count, gSource = DAT_004cd380
SeqEventType* SeqEventType::vfunc2(unsigned int flags) {
    void* p = (*(void**)&DAT_004cd380);
    *(void**)this = (void*)((hulk_intptr)DAT_0042aa7c);
    FUN_002603e0(p, this);
    --DAT_004e7a18.count;
    ((owners::Str_240060 *)&((SeqEventTypeHead *)this)->name)->FUN_00240060();
    FUN_002580e0();
    if (flags & 1)
        DestroySeq_0008d330(this);
    return this;
}

} // namespace fn_fe02c6d2
