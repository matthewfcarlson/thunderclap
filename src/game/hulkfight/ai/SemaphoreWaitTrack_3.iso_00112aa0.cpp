// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00111720..0x001133f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreWaitTrack
#include "tree_prelude.h"


// 0x00112aa0 FUN_00112aa0 (256 B): matches/0x00112aa0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00112aa0
#include "gen/owners.h"
#include "decls/data/game/hulkfight/ai.h"
namespace fn_f97e766f {} using namespace fn_f97e766f;
namespace fn_f97e766f {

/* size_t: tree_prelude.h */

} // namespace fn_f97e766f
inline void* __cdecl operator new(size_t, void* p) {
    return p;
}
namespace fn_f97e766f {

extern void* __cdecl FUN_0008d690(unsigned int);
extern char SetTimeBegin_0010c520(void*, int); /* (unb4) as defined; address taken only */
extern bool SetTimeEnd_0010c530(void*, int); /* (unb4) as defined; address taken only */
extern void* GetKeyword_0010c540(void*); /* (unb4) as defined; address taken only */
extern char SetRandomIntroWait_0010c550(void*, char); /* (unb4) as defined; address taken only */
struct ParamBase_112aa0 {
    virtual void slot0();
    char pad[12];
    void(__cdecl* callback)();
    int tail;
    void FUN_00234960(const char*);
    void FUN_00234a90(const char*);
    void FUN_00234860(const char*);
};
namespace hulkfight {
namespace ai {
class KeywordWaitTrack;
}
} // namespace hulkfight
namespace fight {
template <class T> struct ParamFloatConstRange : ParamBase_112aa0 {
    virtual void slot0();
};
template <class T> struct ParamName : ParamBase_112aa0 {
    virtual void slot0();
};
template <class T> struct ParamBool : ParamBase_112aa0 {
    virtual void slot0();
};
} // namespace fight
extern void __cdecl FUN_002347b0(int*, ParamBase_112aa0**, int);
extern "C" void __cdecl FUN_00112aa0() {
    if (DAT_004e0b84 == 0) {
        ParamBase_112aa0* params[4];
        void* mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>));
        if (mem) {
            ParamBase_112aa0* p = (ParamBase_112aa0*)mem;
            p->FUN_00234960("timeBegin");
            p = new (mem) fight::ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>;
            p->callback = (void (*)())SetTimeBegin_0010c520;
            params[0] = p;
        } else
            params[0] = 0;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>));
        if (mem) {
            ParamBase_112aa0* p = (ParamBase_112aa0*)mem;
            p->FUN_00234960("timeEnd");
            p = new (mem) fight::ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>;
            p->callback = (void (*)())SetTimeEnd_0010c530;
            params[1] = p;
        } else
            params[1] = 0;
        mem = FUN_0008d690((int)sizeof(fight::ParamName<hulkfight::ai::KeywordWaitTrack>));
        if (mem) {
            ParamBase_112aa0* p = (ParamBase_112aa0*)mem;
            p->FUN_00234a90("keyword");
            p = new (mem) fight::ParamName<hulkfight::ai::KeywordWaitTrack>;
            p->callback = (void (*)())GetKeyword_0010c540;
            params[2] = p;
        } else
            params[2] = 0;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool<hulkfight::ai::KeywordWaitTrack>));
        if (mem) {
            ParamBase_112aa0* p = (ParamBase_112aa0*)mem;
            p->FUN_00234860("randomIntroWait");
            p = new (mem) fight::ParamBool<hulkfight::ai::KeywordWaitTrack>;
            p->callback = (void (*)())SetRandomIntroWait_0010c550;
            params[3] = p;
        } else
            params[3] = 0;
        FUN_002347b0(&DAT_004e0b80, params, 4);
    }
    ++DAT_004e0b84;
}
} // namespace fn_f97e766f

