// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00111720..0x001133f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreWaitTrack
#include "tree_prelude.h"


// 0x00112e30 FUN_00112e30 (213 B): matches/0x00112e30.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00112e30
#include "gen/owners.h"
#include "decls/data/game/hulkfight/ai.h"
namespace fn_f84f80a6 {} using namespace fn_f84f80a6;
namespace fn_f84f80a6 {


} // namespace fn_f84f80a6
inline void* __cdecl operator new(size_t, void* p) {
    return p;
}
namespace fn_f84f80a6 {

void* __cdecl FUN_0008d690(unsigned int);
char SetTimeBegin_0010c640(void*, int); /* (unb4) as defined; address taken only */
bool SetTimeEnd_0010c650(void*, int); /* (unb4) as defined; address taken only */
char SetFloatDelayOnEnd_0010c670(void*, char); /* (unb4) as defined; address taken only */
namespace hulkfight {
namespace ai {
class TokenTrack;
}
} // namespace hulkfight
namespace fight {
struct ParamBase_112e30 {
    virtual void v0();
    char pad[12];
    void(__cdecl* callback)();
    char tail[4];
    void FUN_00234960(const char*);
    void FUN_00234860(const char*);
};
template <class T> struct ParamFloatConstRange : ParamBase_112e30 {
    virtual void v0();
};
template <class T> struct ParamBool : ParamBase_112e30 {
    virtual void v0();
};
} // namespace fight
void __cdecl FUN_002347b0(int*, fight::ParamBase_112e30**, int);
extern "C" void __cdecl FUN_00112e30() {
    if (!DAT_004e0b9c) {
        fight::ParamBase_112e30* params[3];
        void* p = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::ai::TokenTrack>));
        if (p) {
            fight::ParamBase_112e30* b = (fight::ParamBase_112e30*)p;
            b->FUN_00234960("timeBegin");
            new (p) fight::ParamFloatConstRange<hulkfight::ai::TokenTrack>;
            b->callback = (void (*)())SetTimeBegin_0010c640;
            params[0] = b;
        } else
            params[0] = 0;
        p = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::ai::TokenTrack>));
        if (p) {
            fight::ParamBase_112e30* b = (fight::ParamBase_112e30*)p;
            b->FUN_00234960("timeEnd");
            new (p) fight::ParamFloatConstRange<hulkfight::ai::TokenTrack>;
            b->callback = (void (*)())SetTimeEnd_0010c650;
            params[1] = b;
        } else
            params[1] = 0;
        p = FUN_0008d690((int)sizeof(fight::ParamBool<hulkfight::ai::TokenTrack>));
        if (p) {
            fight::ParamBase_112e30* b = (fight::ParamBase_112e30*)p;
            b->FUN_00234860("floatDelayOnEnd");
            new (p) fight::ParamBool<hulkfight::ai::TokenTrack>;
            b->callback = (void (*)())SetFloatDelayOnEnd_0010c670;
            params[2] = b;
        } else
            params[2] = 0;
        FUN_002347b0(&DAT_004e0b98, params, 3);
    }
    ++DAT_004e0b9c;
}
} // namespace fn_f84f80a6

