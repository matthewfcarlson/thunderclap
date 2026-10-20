#include "compat/ptr.h"
#include "decls/data/game/global.h"

typedef void (*Callback_54160)();
extern void FUN_00048080();
extern void FUN_000480a0();
extern void FUN_000480d0();
extern void* __cdecl FUN_0008d690(hulk_uintptr);
inline void* __cdecl operator new(unsigned, void* address) {
    return address;
}
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
void __cdecl FUN_00054160() {
    if (DAT_004dc534 == 0) {
        ParamBase_54160* parameters[3];
        void* storage = FUN_0008d690(24);
        if (storage) {
            ((ParamBase_54160*)storage)->FUN_00234960("angle");
            fight::ParamFloatConstRange<CClimbableCondition>* p =
                new (storage) fight::ParamFloatConstRange<CClimbableCondition>;
            p->callback = FUN_00048080;
            parameters[0] = p;
        } else
            parameters[0] = 0;
        storage = FUN_0008d690(24);
        if (storage) {
            ((ParamBase_54160*)storage)->FUN_00234960("arc");
            fight::ParamFloatConstRange<CClimbableCondition>* p =
                new (storage) fight::ParamFloatConstRange<CClimbableCondition>;
            p->callback = FUN_000480a0;
            parameters[1] = p;
        } else
            parameters[1] = 0;
        storage = FUN_0008d690(24);
        if (storage) {
            ((ParamBase_54160*)storage)->FUN_00234860("useIntentionMotion");
            fight::ParamBool<CClimbableCondition>* p = new (storage) fight::ParamBool<CClimbableCondition>;
            p->callback = FUN_000480d0;
            parameters[2] = p;
        } else
            parameters[2] = 0;
        FUN_002347b0(&DAT_004dc530, parameters, 3);
    }
    ++DAT_004dc534;
}
