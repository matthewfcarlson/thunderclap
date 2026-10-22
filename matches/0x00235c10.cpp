#include "compat/ptr.h"
extern "C" char DAT_00427d38[];
class FightNodeBaseCondition_235c10 {
  public:
    int x[3];
    FightNodeBaseCondition_235c10(int);
};
class FightNodeTimeCondition : public FightNodeBaseCondition_235c10 {
  public:
    int y;
    int z;
    FightNodeTimeCondition();
};
FightNodeTimeCondition::FightNodeTimeCondition() : FightNodeBaseCondition_235c10(0) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427d38);
    y = 0;
    z = 0;
}