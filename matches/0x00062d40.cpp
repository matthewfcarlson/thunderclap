// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

struct CPropActorSetStateAction_nv_62d40 {
    int invoke(CPropActorSetStateTrack*, hulk_intptr);
};
extern CPropActorSetStateAction* FUN_0008d690(int);

hulk_intptr CPropActorSetStateTrack::vfunc_12(hulk_intptr param) {
    CPropActorSetStateAction* p = FUN_0008d690(0x24);
    if (p)
        return ((CPropActorSetStateAction_nv_62d40*)(((CPropActorSetStateAction*)(p))))->invoke(this, param);
    return 0;
}
