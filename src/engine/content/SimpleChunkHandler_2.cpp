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
    virtual void f3(int, int, int, int, int);
    virtual void f4();
    virtual void f5(int, int, int, int);
    char pad[12];
    int member10;
};


// 0x00265ff0 content::SimpleChunkHandler::vfunc_3 (27 B): matches/0x00265ff0.cpp
// sym: ?f3@SimpleChunkHandler@fn_f6cd38f1@@UAEXHHHHH@Z
void SimpleChunkHandler::f3(int a, int b, int c, int d, int e) {
    f5(a, b, member10, e);
}

} // namespace fn_f6cd38f1
