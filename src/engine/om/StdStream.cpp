// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00247080..0x00247170 (kind game, layer engine, confidence medium), dominant class om::StdStream
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f5a236af {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f5a236af {} using namespace fn_f5a236af;
#include "engine/om.h"

// ---- declarations shared by the functions below
namespace fn_f5a236af {
typedef int FILE;
extern "C" int __cdecl fclose(FILE*);
extern "C" void __cdecl destroy_0008d330(void*);
extern int hulk_at_0042920c[];
extern int hulk_at_00423f20[];
namespace om {
class StdStream {
  public:
    void* vt;
    char pad[0x18];
    FILE* file;
    unsigned char opened;
    StdStream* vfunc_0(unsigned char);
};
}


// 0x00247080 om::StdStream::vfunc_0 (56 B): matches/0x00247080.cpp
// sym: ?vfunc_0@StdStream@om@fn_f5a236af@@QAEPAV123@E@Z
om::StdStream* om::StdStream::vfunc_0(unsigned char flags) {
    vt = hulk_at_0042920c;
    if (opened)
        fclose(file);
    vt = hulk_at_00423f20;
    if (flags & 1)
        destroy_0008d330(this);
    return this;
}

} // namespace fn_f5a236af
