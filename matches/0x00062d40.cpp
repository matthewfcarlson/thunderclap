// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

struct CPropActorSetStateAction_nv_62d40 {
    int invoke(CPropActorSetStateTrack*, int);
};
extern CPropActorSetStateAction* FUN_0008d690(int);

int CPropActorSetStateTrack::vfunc_12(int param) {
    CPropActorSetStateAction* p = FUN_0008d690(0x24);
    if (p)
        return ((CPropActorSetStateAction_nv_62d40*)(((CPropActorSetStateAction*)(p))))->invoke(this, param);
    return 0;
}
