// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c3650..0x002c3670 (kind game, layer engine, confidence medium), dominant class core::ILanguageChangeCallback
#include "tree_prelude.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_ff00d9ec {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff00d9ec {} using namespace fn_ff00d9ec;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_ff00d9ec {
class pddiObject_2c3650 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_2c3650 : public pddiObject_2c3650 {};
class pddiBaseShader_2c3650 : public pddiShader_2c3650 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_2c3650 : public pddiBaseShader_2c3650 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};

} // namespace fn_ff00d9ec

// 0x002c3650 core::ILanguageChangeCallback::vfunc_3 (6 B): matches/0x002c3650.cpp
// sym: ?vfunc_3_ILanguageChangeCallback@ILanguageChangeCallback@core@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int core::ILanguageChangeCallback::vfunc_3_ILanguageChangeCallback() {
    return 1;
}

