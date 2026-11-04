#include "gen/pure3d.h"
struct Pose_nv_27b240 {
    int DoThing(pure3d::Pose*, int);
};
extern "C" pure3d::Pose* __cdecl FUN_0008d690(int);
int __fastcall target(pure3d::Pose* self, void*) {
    pure3d::Pose* p = FUN_0008d690((int)sizeof(pure3d::Pose));
    if (p)
        return ((Pose_nv_27b240*)(((pure3d::Pose*)(p))))->DoThing(self, 0);
    return 0;
}