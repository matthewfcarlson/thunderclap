#include "gen/hulkfight.h"
#include "gen/owners.h"

class Handle_15c540 {
  public:
    void set(int, int, int);
    void act(int);
};
class Ref_15c540 {
  public:
    Handle_15c540* first();
    Handle_15c540* second();
};
class Manager_15c540 {
  public:
};

void hulkfight::motion::LocomotionSprintAction::vfunc_4() {
    if (this->f_24) {
        Ref_15c540* x = ((Ref_15c540 *)((owners::Object_592a0 *)((*(Manager_15c540 * *)&this->f_20)))->FUN_000592a0());
        Handle_15c540* h = x->first();
        if (h) {
            h->set(this->f_24, 0, (int)0xbf800000);
            h = x->second();
            if (h)
                h->act(0);
        }
    }
}
