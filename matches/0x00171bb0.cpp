#include "gen/hulkfight.h"

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
    void SetFlag(unsigned char);
    void SetPosition(void*);
};
class Manager_171bb0 {
  public:
    Owner_171bb0* GetOwner();
};

void hulkfight::motion::DriftToPositionAction::vfunc_4() {
    Owner_171bb0* o = (*(Manager_171bb0 * *)&this->f_20)->GetOwner();
    if (o) {
        Actor_171bb0* a = o->GetActor();
        if (a) {
            if ((*(Owner_171bb0 * *)&this->f_1c)->flag && this->f_52)
                a->SetPosition((char*)this + 0x40);
            a->field = this->f_51;
            a->SetFlag(this->f_50);
        }
    }
}
