#include "compat/ptr.h"
extern "C" char DAT_00427d14[];
struct FightNodeTimeCondition_235b00 {
    void Init(int);
};
struct Part_235b00 {
    void Init();
};
struct FightNodeParentCondition {
    FightNodeParentCondition* Construct();
    char pad[0x20];
};
FightNodeParentCondition* FightNodeParentCondition::Construct() {
    ((FightNodeTimeCondition_235b00*)this)->Init(0);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427d14);
    *(int*)((char*)this + 0x0c) = 0;
    ((Part_235b00*)((char*)this + 0x10))->Init();
    *((char*)this + 0x1c) = 1;
    return this;
}