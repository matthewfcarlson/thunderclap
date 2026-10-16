#include "gen/global.h"

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
extern const float zeroValue_14900;

float CHitAnimationAction::vfunc_9() {
    Result_14900* p = (Result_14900*)((Queried*)(*(void * *)&this->f_1c))->get();
    if (!p)
        return zeroValue_14900;
    return p->value;
}
