// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00273670..0x002736b0 (kind game, layer engine, confidence high), dominant class core::CompletionCallbackRequest
#include "tree_prelude.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f2a4b06c {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f2a4b06c {} using namespace fn_f2a4b06c;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f2a4b06c {
class CAction {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual bool vfunc_6(void*);
    virtual void a7();
    virtual void a8();
};
class pddiObject_273690 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_273690 : public pddiObject_273690 {};
class pddiBaseShader_273690 : public pddiShader_273690 {
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
class d3dShader_273690 : public pddiBaseShader_273690 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};

} // namespace fn_f2a4b06c

// 0x00273670 core::CompletionCallbackRequest::vfunc_2 (5 B): matches/0x00273670.cpp
// sym: ?vfunc_2@CompletionCallbackRequest@core@@UAE_NH@Z
// Same code shape as 0x00244f40 (propagated; names are from that function)
bool core::CompletionCallbackRequest::vfunc_2(int a) {
    return false;
}

namespace fn_f2a4b06c {

// 0x00273680 FUN_00273680 (5 B): matches/0x00273680.cpp
// sym: ?vfunc_6@CAction@fn_f2a4b06c@@UAE_NPAX@Z
// Same code shape as 0x00013980 (propagated; names are from that function)
bool CAction::vfunc_6(void*) {
    return true;
}

} // namespace fn_f2a4b06c

// 0x00273690 core::CompletionCallbackRequest::vfunc_4 (6 B): matches/0x00273690.cpp
// sym: ?vfunc_4@CompletionCallbackRequest@core@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int core::CompletionCallbackRequest::vfunc_4() {
    return 1;
}

namespace fn_f2a4b06c {

// 0x002736a0 core::CompletionCallbackRequest::vfunc_5 (3 B): matches/0x002736a0.cpp
// sym: ?GetZero@fn_f2a4b06c@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_f2a4b06c
