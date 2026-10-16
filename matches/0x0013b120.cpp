#include "gen/hulkfight.h"

namespace hulkfight {
namespace motion {
struct Obj_13b120 {
    virtual void f0();
    virtual void f1();
    char pad[0x220];
    unsigned char flag;
};
struct Result_13b120 {
    void StopA(Obj_13b120*, int);
    void StopB(Obj_13b120*, int, float);
};
struct Mid_13b120 {
    Result_13b120* Get();
};
struct Owner_13b120 {
    Mid_13b120* Get();
};

} // namespace motion
} // namespace hulkfight
void hulkfight::motion::AnimationVelocityScaledAction::vfunc_4() {
    if (!(*(Obj_13b120 * *)&this->f_24))
        return;
    Result_13b120* p = (*(Owner_13b120 * *)&this->f_20)->Get()->Get();
    if (!p)
        return;
    if ((*(Obj_13b120 * *)&this->f_24)->flag)
        p->StopB((*(Obj_13b120 * *)&this->f_24), 0, -1.0f);
    else
        p->StopA((*(Obj_13b120 * *)&this->f_24), 0);
    if ((*(Obj_13b120 * *)&this->f_24)) {
        (*(Obj_13b120 * *)&this->f_24)->f1();
        (*(Obj_13b120 * *)&this->f_24) = 0;
    }
}
