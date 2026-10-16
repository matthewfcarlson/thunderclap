#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) {
    return p;
}
extern void* __cdecl FUN_0008d690(unsigned int);
extern void __cdecl FUN_00123890();
extern void __cdecl FUN_001238b0();
extern void __cdecl FUN_001238c0();
namespace hulkfight {
namespace ai {
class AcquireTargetCondition;
}
} // namespace hulkfight
struct FUN_00234960 {
    virtual void slot0();
    char pad[12];
    void(__cdecl* callback)();
    int extra;
    FUN_00234960(const char*);
};
struct FUN_00234860 {
    virtual void slot0();
    char pad[12];
    void(__cdecl* callback)();
    int extra;
    FUN_00234860(const char*);
};
namespace fight {
template <class T> struct ParamFloatConstRange : FUN_00234960 {
    ParamFloatConstRange(const char* s) : FUN_00234960(s) {}
    virtual void slot0();
};
template <class T> struct ParamBool : FUN_00234860 {
    ParamBool(const char* s) : FUN_00234860(s) {}
    virtual void slot0();
};
} // namespace fight
extern void __cdecl FUN_002347b0(int*, void**, int);
void target() {
    if (!DAT_004e0dd0) {
        void* p[3];
        void* mem = FUN_0008d690(24);
        if (mem) {
            fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>* a =
                new (mem) fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>("arc");
            a->callback = FUN_00123890;
            p[0] = a;
        } else
            p[0] = 0;
        mem = FUN_0008d690(24);
        if (mem) {
            fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>* a =
                new (mem) fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>("distance");
            a->callback = FUN_001238b0;
            p[1] = a;
        } else
            p[1] = 0;
        mem = FUN_0008d690(24);
        if (mem) {
            fight::ParamBool<hulkfight::ai::AcquireTargetCondition>* a =
                new (mem) fight::ParamBool<hulkfight::ai::AcquireTargetCondition>("validateTarget");
            a->callback = FUN_001238c0;
            p[2] = a;
        } else
            p[2] = 0;
        FUN_002347b0(&DAT_004e0dcc, p, 3);
    }
    ++DAT_004e0dd0;
}
