#include "gen/hulkfight.h"

extern const float gZero_10d7d0;
class Action_10d7d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float Get();
    char pad04[0x10];
    int m14;
    int m18;
};
class State_10d7d0 {
  public:
    char pad[4];
};
class Manager_10d7d0 {
  public:
    void* First();
    char* Second();
};

void hulkfight::ai::ButtonAction::vfunc_4() {
    if ((*(State_10d7d0 * *)&this->f_20) && ((*(Action_10d7d0 * *)&this->f_1c)->m18 == 2 || (*(Action_10d7d0 * *)&this->f_1c)->m18 == 1)) {
        float f = (*(Action_10d7d0 * *)&this->f_1c)->Get();
        if (f < gZero_10d7d0 || f > gZero_10d7d0) {
            Manager_10d7d0* m = (Manager_10d7d0*)(*(State_10d7d0 * *)&this->f_20);
            char* v = ((Manager_10d7d0*)m->First())->Second() + 0x1f58;
            *(int*)(v + (*(Action_10d7d0 * *)&this->f_1c)->m14 * 12) = 0;
        }
    }
}
