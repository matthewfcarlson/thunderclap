#include "gen/hulkfight.h"
#include "gen/owners.h"

class Actor_171bb0;
class Owner_171bb0 {
    char pad[0x25];

  public:
    unsigned char flag;
    Actor_171bb0* GetActor();
};
class Actor_171bb0 {
    char pad[0x2140];

  public:
    unsigned char field;
    void SetPosition(void*);
};
class Manager_171bb0 {
  public:
};

void hulkfight::motion::DriftToPositionAction::vfunc_4() {
    Owner_171bb0* o = ((Owner_171bb0 *)((owners::Object_592a0 *)((*(Manager_171bb0 * *)&this->f_20)))->FUN_000592a0());
    if (o) {
        Actor_171bb0* a = o->GetActor();
        if (a) {
            if ((*(Owner_171bb0 * *)&this->f_1c)->flag && this->f_52)
                a->SetPosition((char*)this + 0x40);
            a->field = this->f_51;
            ((owners::Target_35ce0 *)a)->FUN_00035ce0(this->f_50);
        }
    }
}
