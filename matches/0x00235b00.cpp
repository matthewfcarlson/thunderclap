#include "gen/fight.h"

#include "compat/ptr.h"
extern "C" char DAT_00427d14[];
struct FightNodeTimeCondition_235b00 {
    void Init(int);
};
struct Part_235b00 {
    void Init();
};

fight::FightNodeParentCondition* fight::FightNodeParentCondition::FUN_00235b00() {
    ((FightNodeTimeCondition_235b00*)this)->Init(0);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427d14);
    *(int*)((char*)this + 0x0c) = 0;
    ((Part_235b00*)((char*)this + 0x10))->Init();
    *((char*)this + 0x1c) = 1;
    return (fight::FightNodeParentCondition*)(this);
}
