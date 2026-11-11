// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00234e50..0x00234f10 (kind game, layer engine, confidence medium), dominant class fight::ParamValueVector
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fa28d91f {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa28d91f {} using namespace fn_fa28d91f;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_fa28d91f {
extern int hulk_at_00427b94;
class ParamValue {
  public:
    virtual void F();
    char pad[4];
};
class ValuePart {
  public:
    ValuePart(int);
};
class ParamValueVector : public ParamValue {
    ValuePart part;

  public:
    ParamValueVector(hulk_intptr);
    virtual void G() HULK_PURE64;
};
namespace fight {
struct ValueResult { unsigned first, second, third; };
}
namespace fight {
struct Reader {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual char vfunc_5(unsigned, unsigned, ValueResult *);
};
}
namespace fight {
struct ParamValueVector {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual char vfunc_5(unsigned, unsigned, Reader *);
    virtual void FUN_00344f51(unsigned, ValueResult *);
    unsigned reserved;
    unsigned field8;
    unsigned fieldC;
};
}


// 0x00234e50 FUN_00234e50 (34 B): matches/0x00234e50.cpp
// sym: ??0ParamValueVector@fn_fa28d91f@@QAE@H@Z
ParamValueVector::ParamValueVector(hulk_intptr x) : part(x) {
    *((hulk_intptr*)this) = (hulk_intptr)&hulk_at_00427b94;
}


// 0x00234e80 fight::ParamValueVector::vfunc_5 (88 B): equivalent/0x00234e80.cpp
// sym: ?vfunc_5@ParamValueVector@fight@fn_fa28d91f@@UAEDIIPAUReader@23@@Z @735f704bf705 @w5c9902472b50
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// fight::ParamValueVector::vfunc_5 @ 0x00234e80
namespace fight {
char ParamValueVector::vfunc_5(unsigned destination, unsigned, Reader *reader) {
    ValueResult result = {0, 0, 0};
    char success = reader->vfunc_5(field8, fieldC, &result);
    if (success)
        FUN_00344f51(destination, &result);
    return success;
}
}

} // namespace fn_fa28d91f
