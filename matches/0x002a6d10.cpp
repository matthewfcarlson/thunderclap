#include "gen/pure3d.h"
#include "gen/owners.h"

struct Track_2a6d10;
struct Channel_2a6d10 {
    Track_2a6d10* FUN_00288960(unsigned int, unsigned int);
};
struct Animation_2a6d10 {
};
struct Track_2a6d10 {
    int unused;
    int count;
};
struct Geometry_2a6d10 {
    void FUN_002d0d20(void*, int);
    void FUN_002d0da0(void*, float, int);
};
namespace pure3d {

} // namespace pure3d
void pure3d::VertexAnimController::vfunc_7() {
    Track_2a6d10* track = ((Channel_2a6d10 *)((owners::Target_288a10 *)((*(Animation_2a6d10 * *)&this->f_3c)))->FUN_00288a10(0))->FUN_00288960(0x58545256, 0x544e49);
    if (track) {
        int first, second;
        float firstTime, secondTime;
        void* firstData;
        void* secondData;
        ((owners::Table_289f80 *)track)->FUN_00289f80(this->f_34, &first, &second);
        ((owners::X_28a080 *)track)->FUN_0028a080(first, &firstTime, (int *)(&firstData));
        (*(Geometry_2a6d10 * *)&this->f_40)->FUN_002d0d20(firstData, 1);
        if (first != second) {
            ((owners::X_28a080 *)track)->FUN_0028a080(second, &secondTime, (int *)(&secondData));
            (*(Geometry_2a6d10 * *)&this->f_40)->FUN_002d0da0(secondData, (this->f_34 - firstTime) / (secondTime - firstTime), track->count);
        }
    }
}
