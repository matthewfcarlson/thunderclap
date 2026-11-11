// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010e250..0x0010e350 (kind game, layer game, confidence medium), dominant class hulkfight::ai::SemaphoreWaitAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f7fa9090 {
#define TREE_TU_END }
namespace fn_f7fa9090 {} using namespace fn_f7fa9090;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f7fa9090 {
extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
typedef unsigned int u32_10e250;
extern void FUN_00344e74(void*, int, void*, void*, int);

} // namespace fn_f7fa9090

// 0x0010e250 hulkfight::ai::AIHistoryCountTrack::vfunc_10 (32 B): matches/0x0010e250.cpp
// sym: ?vfunc_10@AIHistoryCountTrack@ai@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::ai::AIHistoryCountTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr __p2) { void * p = (void *)__p2;

    FUN_00344e74(p, 0, (void*)((hulk_intptr)DAT_00494b44), (void*)((hulk_intptr)DAT_00494b60), 0);
    return (int)(0);
}


// 0x0010e270 hulkfight::ai::AIHistoryCountTrack::vfunc_7 (7 B): matches/0x0010e270.cpp
// sym: ?vfunc_7@AIHistoryCountTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::ai::AIHistoryCountTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x0010e280 hulkfight::ai::SemaphoreWaitAction::vfunc_3 (63 B): matches/0x0010e280.cpp [wrapped: conflict: hulkfight::ai::SemaphoreWaitAction]
// sym: ?vfunc_3@SemaphoreWaitAction@ai@hulkfight@fn_0010e280@@UAEDHH@Z
namespace fn_0010e280 {
struct Data {
    char pad[0x18];
    int value;
    char pad2[4];
    unsigned char flag;
};
struct Result {
    void send(int*, int, unsigned char);
};
struct Getter {
    Result* get();
};
struct Semaphore {
    Getter* get();
};
namespace hulkfight {
namespace ai {
class SemaphoreWaitAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char vfunc_3(int, int);
    virtual void v4();
    virtual void v5();
    char pad[0x1c - 4];
    Data* data;
    Semaphore* sem;
    int state;
};
} // namespace ai
} // namespace hulkfight
char hulkfight::ai::SemaphoreWaitAction::vfunc_3(int, int) {
    if (!sem)
        return 0;
    Result* r = sem->get()->get();
    state = 0;
    r->send(&data->value, 1, data->flag);
    return 1;
}
} // namespace fn_0010e280


// 0x0010e2c0 hulkfight::ai::SemaphoreWaitAction::vfunc_5 (135 B): matches/0x0010e2c0.cpp [wrapped: conflict: hulkfight::ai::SemaphoreWaitAction]
// sym: ?vfunc_5@SemaphoreWaitAction@ai@hulkfight@fn_0010e2c0@@UAE_NHM@Z
namespace fn_0010e2c0 {
// hulkfight::ai::SemaphoreWaitAction::vfunc_5 @ 0x0010e2c0
struct Settings_10e2c0 {
    char pad00[0x18];
    char timer[8];
    char pad20;
    unsigned char useGlobal;
    char pad22[2];
    float limit;
};

struct Globals_10e2c0 {
    char pad00[0x1d08];
    float limit;
    bool FUN_00036fd0(void *timer);
    bool FUN_00037040(void *timer, int a, int b);
};

struct Table_10e2c0 {
    Globals_10e2c0 *FUN_00059a30();
};

struct Owner_10e2c0 {
    Table_10e2c0 *FUN_000592a0();
};


namespace hulkfight {
namespace ai {

class SemaphoreWaitAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int cancelled, float dt);
    char pad04[0x18];
    Settings_10e2c0 *settings;
    Owner_10e2c0 *owner;
    float elapsed;
};

bool SemaphoreWaitAction::vfunc_5(int cancelled, float dt)
{
    if (cancelled)
        return true;
    Globals_10e2c0 *globals = owner->FUN_000592a0()->FUN_00059a30();
    if (!globals)
        return true;
    elapsed += dt;
    Settings_10e2c0 *s = settings;
    float limit = s->useGlobal ? globals->limit : s->limit;
    if (limit != 0.0f && elapsed >= limit) {
        globals->FUN_00037040(s->timer, 0, 1);
        return false;
    }
    return globals->FUN_00036fd0(s->timer);
}

}
}
} // namespace fn_0010e2c0

