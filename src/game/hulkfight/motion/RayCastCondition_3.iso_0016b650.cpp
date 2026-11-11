// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a910..0x0016c600 (kind game, layer game, confidence high), dominant class hulkfight::motion::RayCastCondition
#include "tree_prelude.h"


// 0x0016b650 FUN_0016b650 (192 B): matches/0x0016b650.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_0016b650
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
namespace fn_fe582589 {} using namespace fn_fe582589;
namespace fn_fe582589 {

typedef unsigned int uint;
void __cdecl SetCompare_001656c0();
void __cdecl SetLocomotionMotionState_001656d0();
void* __cdecl FUN_0008d690(uint);
void __cdecl FUN_002347b0(void*, void*, uint);

} // namespace fn_fe582589
inline void* operator new(size_t, void* p) {
    return p;
}
namespace fn_fe582589 {

namespace hulkfight {
namespace motion {
class TargetLocomotionMotionStateCondition;
}
} // namespace hulkfight
namespace fight {
template <class T> struct ParamEnumConstList {
    virtual void slot0();
    char padding[12];
    void* values;
    uint count;
    void(__cdecl* callback)();
    uint extra;
    void FUN_00234cc0(const char*);
};
} // namespace fight
typedef fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition> List_16b650;
extern "C" void __cdecl FUN_0016b650() {
    if (!(*(uint*)&DAT_004e124c)) {
        List_16b650* lists[2];
        void* p = FUN_0008d690((int)sizeof(List_16b650));
        if (p) {
            uint n = (*(uint*)&DAT_00427760);
            ((List_16b650*)p)->FUN_00234cc0("compare");
            List_16b650* x = new (p) List_16b650;
            x->values = ((uint*)&DAT_00427758);
            x->count = n;
            x->callback = SetCompare_001656c0;
            lists[0] = x;
        } else
            lists[0] = 0;
        p = FUN_0008d690((int)sizeof(List_16b650));
        if (p) {
            uint n = (*(uint*)&DAT_003f5bbc);
            ((List_16b650*)p)->FUN_00234cc0("locomotionMotionState");
            List_16b650* x = new (p) List_16b650;
            x->values = ((uint*)&DAT_0048f590);
            x->count = n;
            x->callback = SetLocomotionMotionState_001656d0;
            lists[1] = x;
        } else
            lists[1] = 0;
        FUN_002347b0(((uint*)&DAT_004e1248), lists, 2);
    }
    ++(*(uint*)&DAT_004e124c);
}
} // namespace fn_fe582589

