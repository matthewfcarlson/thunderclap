#include "decls/data/game/hulkfight/ai.h"

typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* p) {
    return p;
}
extern void* __cdecl FUN_0008d690(unsigned int);
extern void __cdecl FUN_0010c520();
extern void __cdecl FUN_0010c530();
extern void __cdecl FUN_0010c540();
extern void __cdecl FUN_0010c550();
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
void __cdecl FUN_00112aa0() {
    if (DAT_004e0b84 == 0) {
        ParamBase_112aa0* params[4];
        void* mem = FUN_0008d690(24);
        if (mem) {
            ParamBase_112aa0* p = (ParamBase_112aa0*)mem;
            p->FUN_00234960("timeBegin");
            p = new (mem) fight::ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>;
            p->callback = FUN_0010c520;
            params[0] = p;
        } else
            params[0] = 0;
        mem = FUN_0008d690(24);
        if (mem) {
            ParamBase_112aa0* p = (ParamBase_112aa0*)mem;
            p->FUN_00234960("timeEnd");
            p = new (mem) fight::ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>;
            p->callback = FUN_0010c530;
            params[1] = p;
        } else
            params[1] = 0;
        mem = FUN_0008d690(24);
        if (mem) {
            ParamBase_112aa0* p = (ParamBase_112aa0*)mem;
            p->FUN_00234a90("keyword");
            p = new (mem) fight::ParamName<hulkfight::ai::KeywordWaitTrack>;
            p->callback = FUN_0010c540;
            params[2] = p;
        } else
            params[2] = 0;
        mem = FUN_0008d690(24);
        if (mem) {
            ParamBase_112aa0* p = (ParamBase_112aa0*)mem;
            p->FUN_00234860("randomIntroWait");
            p = new (mem) fight::ParamBool<hulkfight::ai::KeywordWaitTrack>;
            p->callback = FUN_0010c550;
            params[3] = p;
        } else
            params[3] = 0;
        FUN_002347b0(&DAT_004e0b80, params, 4);
    }
    ++DAT_004e0b84;
}