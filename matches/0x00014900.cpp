#include "gen/global.h"
#include "decls/data/game/global.h"
// data: zeroValue_14900 = DAT_003f32e0

struct CProceduralDurationAnimationAction_14900 {
    char pad[0x1c];
    void* member;
};
struct Queried {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void* get();
};
struct Result_14900 {
    char pad[0x58];
    float value;
};

hulk_freg CHitAnimationAction::vfunc_9() {
    Result_14900* p = (Result_14900*)((Queried*)(*(void * *)&this->f_1c))->get();
    if (!p)
        return DAT_003f32e0;
    return p->value;
}
