// cl-flags: /O1
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00023750..0x000240b0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_ff92353c {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff92353c {} using namespace fn_ff92353c;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_ff92353c {
class T_23c80 {
  public:
    virtual void A();
    char Get();
};


// 0x00023c80 FUN_00023c80 (7 B): matches/0x00023c80.cpp
// sym: ?Get@T_23c80@fn_ff92353c@@QAEDXZ
char T_23c80::Get() {
    return *(char*)((char*)this + 0x1d4d);
}

} // namespace fn_ff92353c
