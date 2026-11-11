// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00266900..0x00266950 (kind game, layer engine, confidence medium), dominant class content::LoadRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f6a56b1c {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6a56b1c {} using namespace fn_f6a56b1c;
#include "engine/content.h"

// ---- declarations shared by the functions below
namespace fn_f6a56b1c {
class Ref_266900 {
  public:
    virtual void f0();
    virtual void f1();
};
extern char vtLoad_266900[];
extern char vtRef_266900[];
namespace content {
class LoadRequest {
  public:
    hulk_intptr vt;
    char p[0x14];
    Ref_266900* a;
    Ref_266900* c;
    char q[0x104];
    Ref_266900* b;
    LoadRequest* vfunc_2(bool);
};
}
void thunk(content::LoadRequest*);


// 0x00266900 content::LoadRequest::vfunc_2 (76 B): matches/0x00266900.cpp
// sym: ?vfunc_2@LoadRequest@content@fn_f6a56b1c@@QAEPAV123@_N@Z
content::LoadRequest* content::LoadRequest::vfunc_2(bool d) {
    vt = (hulk_intptr)vtLoad_266900;
    if (a)
        a->f1();
    if (b)
        b->f1();
    if (c)
        c->f1();
    vt = (hulk_intptr)vtRef_266900;
    if (d & 1)
        thunk(this);
    return this;
}

} // namespace fn_f6a56b1c
