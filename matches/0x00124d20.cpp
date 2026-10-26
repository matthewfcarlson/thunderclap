#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Obj_124d20;
class Actor_124d20 {
  public:
    char pad[0x10];
    char flag;
};
class Obj_124d20 {
  public:
    Obj_124d20* Resolve();
    Obj_124d20* Check();
    void Apply(int a, int b);
    char pad[0x32c];
    char flag;
};

bool hulkfight::ai::TargetClearAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    if (!(*(Obj_124d20 * *)&this->f_20))
        return false;
    Obj_124d20* r = (*(Obj_124d20 * *)&this->f_20)->Resolve();
    if (!r)
        return false;
    Obj_124d20* r2 = r->Check();
    if (!r2)
        return false;
    if ((*(Actor_124d20 * *)&this->f_1c)->flag != 0 || r2->flag == 0)
        r2->Apply(0, 0);
    return true;
}
