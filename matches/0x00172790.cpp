#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct Obj_172790 {
    char pad[0x1b0c];
    float amount;
    float Get();
    void Set(float, int);
};
struct Mid_172790 {
    Obj_172790* GetObj();
};
struct Source_172790 {
    Mid_172790* GetMid();
};
struct Param_172790 {
    char pad[0x10];
    float amount;
};
namespace hulkfight {
namespace motion {

} // namespace motion
} // namespace hulkfight
bool hulkfight::motion::CriticalMassDrainAction::vfunc_3(int x, int y) {
    if (!(*(Source_172790 * *)&this->f_20))
        return (bool)(0);
    Mid_172790* m = (*(Source_172790 * *)&this->f_20)->GetMid();
    if (!m)
        return (bool)(0);
    Obj_172790* o = m->GetObj();
    if (!o)
        return (bool)(0);
    hulk_freg amt = o->amount;
    if (amt >= o->Get())
        o->Set(amt - (*(Param_172790 * *)&this->f_1c)->amount, 1);
    return (bool)(0);
}
