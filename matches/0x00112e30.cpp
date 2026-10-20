#include "decls/data/game/hulkfight/ai.h"

inline void* __cdecl operator new(unsigned int, void* p) {
    return p;
}
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0010c640();
void __cdecl FUN_0010c650();
void __cdecl FUN_0010c670();
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
void __cdecl FUN_00112e30() {
    if (!DAT_004e0b9c) {
        fight::ParamBase_112e30* params[3];
        void* p = FUN_0008d690(24);
        if (p) {
            fight::ParamBase_112e30* b = (fight::ParamBase_112e30*)p;
            b->FUN_00234960("timeBegin");
            new (p) fight::ParamFloatConstRange<hulkfight::ai::TokenTrack>;
            b->callback = FUN_0010c640;
            params[0] = b;
        } else
            params[0] = 0;
        p = FUN_0008d690(24);
        if (p) {
            fight::ParamBase_112e30* b = (fight::ParamBase_112e30*)p;
            b->FUN_00234960("timeEnd");
            new (p) fight::ParamFloatConstRange<hulkfight::ai::TokenTrack>;
            b->callback = FUN_0010c650;
            params[1] = b;
        } else
            params[1] = 0;
        p = FUN_0008d690(24);
        if (p) {
            fight::ParamBase_112e30* b = (fight::ParamBase_112e30*)p;
            b->FUN_00234860("floatDelayOnEnd");
            new (p) fight::ParamBool<hulkfight::ai::TokenTrack>;
            b->callback = FUN_0010c670;
            params[2] = b;
        } else
            params[2] = 0;
        FUN_002347b0(&DAT_004e0b98, params, 3);
    }
    ++DAT_004e0b9c;
}