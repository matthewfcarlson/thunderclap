#include "gen/hulkfight.h"

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
namespace hulkfight {
namespace ai {
} // namespace ai
} // namespace hulkfight
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
