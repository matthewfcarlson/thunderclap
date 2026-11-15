// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00128240..0x001296f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::AcquireTargetTrack
#include "tree_prelude.h"


// 0x00128ed0 FUN_00128ed0 (213 B): matches/0x00128ed0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00128ed0
#include "gen/owners.h"
#include "decls/data/game/unknown.h"
namespace fn_f8872bd6 {} using namespace fn_f8872bd6;
namespace fn_f8872bd6 {


} // namespace fn_f8872bd6
inline void* operator new(size_t, void* p) {
    return p;
}
namespace fn_f8872bd6 {

extern void* __cdecl FUN_0008d690(unsigned int);
extern char FUN_00123890(void*, float); /* (unb4) as defined; address taken only */
extern char FUN_001238b0(void*, int); /* (unb4) as defined; address taken only */
extern char FUN_001238c0(void*, char); /* (unb4) as defined; address taken only */
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
extern "C" void FUN_00128ed0() {
    if (!DAT_004e0dd0) {
        void* p[3];
        void* mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>));
        if (mem) {
            fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>* a =
                new (mem) fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>("arc");
            a->callback = (void (*)())FUN_00123890;
            p[0] = a;
        } else
            p[0] = 0;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>));
        if (mem) {
            fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>* a =
                new (mem) fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>("distance");
            a->callback = (void (*)())FUN_001238b0;
            p[1] = a;
        } else
            p[1] = 0;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool<hulkfight::ai::AcquireTargetCondition>));
        if (mem) {
            fight::ParamBool<hulkfight::ai::AcquireTargetCondition>* a =
                new (mem) fight::ParamBool<hulkfight::ai::AcquireTargetCondition>("validateTarget");
            a->callback = (void (*)())FUN_001238c0;
            p[2] = a;
        } else
            p[2] = 0;
        FUN_002347b0(&DAT_004e0dcc, p, 3);
    }
    ++DAT_004e0dd0;
}
} // namespace fn_f8872bd6

