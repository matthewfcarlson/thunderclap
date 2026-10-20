// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 12/12)
// hulkfight::scenario::Event_LocomotionStateNameCondition::vfunc_6 @ 0x001a4bf0
#include "compat/ptr.h"
extern char DAT_00494b44;
extern char DAT_004c13d0;
void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
struct ScenarioEvent {
    char pad[4];
    int kind;
    char rest[16];
    int stateName;
};
struct ScenarioParams {
    ScenarioEvent* FUN_001d03c0();
};
struct Event_LocomotionStateNameCondition {
    void* vtable;
    char pad[8];
    int comparison;
    int name;
    unsigned int vfunc_6(int unused0, void* params, int unused2);
};
unsigned int Event_LocomotionStateNameCondition::vfunc_6(int unused0, void* params, int unused2)
{
    ScenarioParams* scenario = (ScenarioParams*)FUN_00344e74(params, 0, &DAT_00494b44, &DAT_004c13d0, 0);
    if (!scenario) return 0;
    ScenarioEvent* event = scenario->FUN_001d03c0();
    if (event->kind != 15) return (hulk_uintptr)event & ~255u;
    if (comparison == 0) return event->stateName == name;
    if (comparison == 1) return event->stateName != name;
    return (comparison - 1) & ~255u;
}