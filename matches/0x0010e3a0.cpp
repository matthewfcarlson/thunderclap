#include "gen/hulkfight.h"
#include "gen/owners.h"

struct Owner {
    char pad[0x18];
    int sem;
    char pad2[5];
    char active;
};
class Agent {
  public:
    Agent* Next();
    void Clear();
};
namespace hulkfight {
namespace ai {

} // namespace ai
} // namespace hulkfight
void hulkfight::ai::SemaphoreClearAction::vfunc_4() {
    if ((*(Agent * *)&this->f_20)) {
        Agent* a = ((Agent *)((owners::Object_592a0 *)((*(Agent * *)&this->f_20)))->FUN_000592a0())->Next();
        Owner* o = (*(Owner * *)&this->f_1c);
        if (o->active) {
            a->Clear();
            return;
        }
        ((owners::C_37040 *)a)->FUN_00037040((hulk_intptr)(Owner *)((Owner*)((char*)o + 0x18)), 0, 1);
    }
}
