// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010e1f0..0x0010e250 (kind game, layer game, confidence medium), dominant class hulkfight::ai::AIHistorySetAction
#include "tree_prelude.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fe46a1bb {
#define TREE_TU_END }
namespace fn_fe46a1bb {} using namespace fn_fe46a1bb;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fe46a1bb {
struct Pair {
    int a, b;
    void Set(const Pair*);
};
struct Actor {
    char pad[0x1b98];
    Pair p;
    int count;
};
struct Source {
    char pad[0x18];
    Pair p;
};
struct Handle {
    Actor* Get();
};
struct Thing {
    Handle* Get();
};

} // namespace fn_fe46a1bb

// 0x0010e1f0 hulkfight::ai::AIHistorySetAction::vfunc_4 (86 B): matches/0x0010e1f0.cpp
// sym: ?vfunc_4@AIHistorySetAction@ai@hulkfight@@UAEXXZ
 // namespace hulkfight
void hulkfight::ai::AIHistorySetAction::vfunc_4() {
    if ((*(Thing * *)&this->f_20)) {
        Actor* a = (*(Thing * *)&this->f_20)->Get()->Get();
        Pair* p = &(*(Source * *)&this->f_1c)->p;
        Pair* q = &a->p;
        if (q->a == p->a && q->b == p->b)
            ++a->count;
        else {
            q->Set(p);
            a->count = 1;
        }
    }
}

