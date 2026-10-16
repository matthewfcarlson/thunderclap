#include "gen/hulkfight.h"

struct Owner {
    char pad[0x18];
    int sem;
    char pad2[5];
    char active;
};
class Agent {
  public:
    Agent* Get();
    Agent* Next();
    void Clear();
    void Clear2(Owner*, int, int);
};
namespace hulkfight {
namespace ai {

} // namespace ai
} // namespace hulkfight
void hulkfight::ai::SemaphoreClearAction::vfunc_4() {
    if ((*(Agent * *)&this->f_20)) {
        Agent* a = (*(Agent * *)&this->f_20)->Get()->Next();
        Owner* o = (*(Owner * *)&this->f_1c);
        if (o->active) {
            a->Clear();
            return;
        }
        a->Clear2((Owner*)((char*)o + 0x18), 0, 1);
    }
}
