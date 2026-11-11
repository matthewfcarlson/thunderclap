// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00247170..0x002471f0 (kind game, layer engine, confidence medium), dominant class om::CoreFileStream
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f8f4fb53 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f8f4fb53 {} using namespace fn_f8f4fb53;
#include "engine/om.h"

// ---- declarations shared by the functions below
namespace fn_f8f4fb53 {
struct Handle_247170 {
    virtual void a();
    virtual void close();
};
extern void* hulk_at_00423f20[];
namespace om {
class CoreFileStream {
  public:
    void* vt;
    char pad[0x18];
    Handle_247170* member;
    CoreFileStream* vfunc_0(unsigned char);
};
}


// 0x00247170 om::CoreFileStream::vfunc_0 (45 B): matches/0x00247170.cpp
// sym: ?vfunc_0@CoreFileStream@om@fn_f8f4fb53@@QAEPAV123@E@Z
om::CoreFileStream* om::CoreFileStream::vfunc_0(unsigned char p) {
    Handle_247170* h = member;
    vt = corevt;
    h->close();
    vt = hulk_at_00423f20;
    if (p & 1)
        cleanup(this);
    return this;
}

} // namespace fn_f8f4fb53
