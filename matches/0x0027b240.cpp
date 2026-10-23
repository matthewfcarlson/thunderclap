#include "gen/pure3d.h"
struct Pose_nv_27b240 {
    int DoThing(pure3d::Pose*, int);
};
extern pure3d::Pose* __cdecl GetThing(int);
int __fastcall target(pure3d::Pose* self, void*) {
    pure3d::Pose* p = GetThing(0x2c);
    if (p)
        return ((Pose_nv_27b240*)(((pure3d::Pose*)(p))))->DoThing(self, 0);
    return 0;
}