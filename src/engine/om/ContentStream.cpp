// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002471f0..0x00247220 (kind game, layer engine, confidence medium), dominant class om::ContentStream
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fb37a5c7 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb37a5c7 {} using namespace fn_fb37a5c7;
#include "engine/om.h"

// ---- declarations shared by the functions below
namespace fn_fb37a5c7 {
struct Handle_2471f0 {
    virtual void a();
    virtual void close();
};
extern void* hulk_at_00423f20[];
namespace om {
class ContentStream {
  public:
    void* vt;
    char pad[0x18];
    Handle_2471f0* member;
    ContentStream* vfunc_0(unsigned char);
};
}


// 0x002471f0 om::ContentStream::vfunc_0 (45 B): matches/0x002471f0.cpp
// sym: ?vfunc_0@ContentStream@om@fn_fb37a5c7@@QAEPAV123@E@Z
// Same code shape as 0x00247170 (propagated; names are from that function)
om::ContentStream* om::ContentStream::vfunc_0(unsigned char p) {
    Handle_2471f0* h = member;
    vt = corevt;
    h->close();
    vt = hulk_at_00423f20;
    if (p & 1)
        cleanup(this);
    return this;
}

} // namespace fn_fb37a5c7
