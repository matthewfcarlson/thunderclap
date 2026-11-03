#include "gen/hulkfight.h"

#include "compat/ptr.h"
#include "gen/owners.h"
class Ref {
  public:
    virtual void f0();
    virtual void release();
};
class Anim {
    char pad[0x40];

  public:
    int state;
    void set(int, int, int);
};
namespace hulkfight {
namespace motion {

} // namespace motion
} // namespace hulkfight
void hulkfight::motion::PropAnimationAction::vfunc_4() {
    if ((*(Anim * *)&this->f_24)) {
        if ((*(Anim * *)&this->f_24)->state == -1 && ((owners::C_27cb70 *)((*(Anim * *)&this->f_24)))->FUN_0027cb70() == (hulk_intptr)(*(Ref * *)&this->f_28))
            (*(Anim * *)&this->f_24)->set(0, 0, 0);
        if ((*(Ref * *)&this->f_28)) {
            (*(Ref * *)&this->f_28)->release();
            (*(Ref * *)&this->f_28) = 0;
        }
    }
}
