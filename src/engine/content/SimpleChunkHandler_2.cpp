// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00265ff0..0x00266090 (kind game, layer engine, confidence medium), dominant class content::SimpleChunkHandler
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f6cd38f1 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6cd38f1 {} using namespace fn_f6cd38f1;
#include "engine/content.h"

// ---- declarations shared by the functions below
namespace fn_f6cd38f1 {
class SimpleChunkHandler {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(void*, void*, void*, int, void*);
    virtual void f4();
    virtual void f5(void*, void*, void*, void*);
    // (x64t14) decls/loaders.h HulkChunkHandler's words after the vftable: the reader a pointer (was a 12-byte pad and an
    // int, natively at +0x14); vfunc_3's arguments are P3DFileHandler 0x00265cd0's pointers (were ints: truncated)
    int refs;
    int id;
    int f0c;
    void* member10;
};


// 0x00265ff0 content::SimpleChunkHandler::vfunc_3 (27 B): matches/0x00265ff0.cpp
// sym: ?f3@SimpleChunkHandler@fn_f6cd38f1@@UAEXPAX00H0@Z
void SimpleChunkHandler::f3(void* a, void* b, void* c, int d, void* e) {
    f5(a, b, member10, e);
}

} // namespace fn_f6cd38f1
