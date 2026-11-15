// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052720..0x00055210 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x00054160 FUN_00054160 (213 B): matches/0x00054160.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00054160
#include "gen/owners.h"
#include "decls/data/game/global.h"
namespace fn_fdde533c {} using namespace fn_fdde533c;
namespace fn_fdde533c {

typedef void (*Callback_54160)();
extern char SetAngle_00048080(void*, float); /* (unb4) as defined; address taken only */
extern bool SetArc_000480a0(void*, float); /* (unb4) as defined; address taken only */
extern char SetUseIntentionMotion_000480d0(void*, char); /* (unb4) as defined; address taken only */
extern void* __cdecl FUN_0008d690(unsigned);

} // namespace fn_fdde533c
inline void* __cdecl operator new(size_t, void* address) {
    return address;
}
namespace fn_fdde533c {

class CClimbableCondition;
struct ParamBase_54160 {
    virtual void slot0();
    char data[12];
    Callback_54160 callback;
    unsigned tail;
    void FUN_00234960(const char*);
    void FUN_00234860(const char*);
};
namespace fight {
template <class T> struct ParamFloatConstRange : ParamBase_54160 {
    virtual void slot0();
};
template <class T> struct ParamBool : ParamBase_54160 {
    virtual void slot0();
};
} // namespace fight
extern void __cdecl FUN_002347b0(unsigned*, ParamBase_54160**, unsigned);
extern "C" void __cdecl FUN_00054160() {
    if (DAT_004dc534 == 0) {
        ParamBase_54160* parameters[3];
        void* storage = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CClimbableCondition>));
        if (storage) {
            ((ParamBase_54160*)storage)->FUN_00234960("angle");
            fight::ParamFloatConstRange<CClimbableCondition>* p =
                new (storage) fight::ParamFloatConstRange<CClimbableCondition>;
            p->callback = (void (*)())SetAngle_00048080;
            parameters[0] = p;
        } else
            parameters[0] = 0;
        storage = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CClimbableCondition>));
        if (storage) {
            ((ParamBase_54160*)storage)->FUN_00234960("arc");
            fight::ParamFloatConstRange<CClimbableCondition>* p =
                new (storage) fight::ParamFloatConstRange<CClimbableCondition>;
            p->callback = (void (*)())SetArc_000480a0;
            parameters[1] = p;
        } else
            parameters[1] = 0;
        storage = FUN_0008d690((int)sizeof(fight::ParamBool<CClimbableCondition>));
        if (storage) {
            ((ParamBase_54160*)storage)->FUN_00234860("useIntentionMotion");
            fight::ParamBool<CClimbableCondition>* p = new (storage) fight::ParamBool<CClimbableCondition>;
            p->callback = (void (*)())SetUseIntentionMotion_000480d0;
            parameters[2] = p;
        } else
            parameters[2] = 0;
        FUN_002347b0(&DAT_004dc530, parameters, 3);
    }
    ++DAT_004dc534;
}
} // namespace fn_fdde533c

