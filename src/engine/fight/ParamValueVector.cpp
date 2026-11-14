// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00234e50..0x00234f10 (kind game, layer engine, confidence medium), dominant class fight::ParamValueVector
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter classes' real constructors
#include "compat/ptr.h"
#include "gen/fight.h"
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


} // namespace fn_fa28d91f

// 0x00234e50 FUN_00234e50 (34 B): matches/0x00234e50.cpp
// sym: ??0ParamValueVector@fight@@QAE@PBD@Z
// (gx2, D18) the constructor the parameter registrations call (`new ParamX<T>(name, setter)`)
::fight::ParamValueVector::ParamValueVector(const char* name) : ::fight::ParamValue(name) {}

namespace fn_fa28d91f {




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
