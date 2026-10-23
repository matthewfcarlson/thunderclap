#include "gen/hulkfight.h"

#include "compat/ptr.h"
class Ref {
  public:
    virtual void f0();
    virtual void release();
};
class Anim {
    char pad[0x40];

  public:
    int state;
    int get();
    void set(int, int, int);
};
namespace hulkfight {
namespace motion {

} // namespace motion
} // namespace hulkfight
void hulkfight::motion::PropAnimationAction::vfunc_4() {
    if ((*(Anim * *)&this->f_24)) {
        if ((*(Anim * *)&this->f_24)->state == -1 && (*(Anim * *)&this->f_24)->get() == (hulk_intptr)(*(Ref * *)&this->f_28))
            (*(Anim * *)&this->f_24)->set(0, 0, 0);
        if ((*(Ref * *)&this->f_28)) {
            (*(Ref * *)&this->f_28)->release();
            (*(Ref * *)&this->f_28) = 0;
        }
    }
}
