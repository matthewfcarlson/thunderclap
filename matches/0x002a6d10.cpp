#include "gen/pure3d.h"

struct Track_2a6d10;
struct Channel_2a6d10 {
    Track_2a6d10* FUN_00288960();
};
struct Animation_2a6d10 {
    Channel_2a6d10* FUN_00288a10(int, unsigned int, unsigned int);
};
struct Track_2a6d10 {
    int unused;
    int count;
    void FUN_00289f80(float, int*, int*);
    void FUN_0028a080(int, float*, void**);
};
struct Geometry_2a6d10 {
    void FUN_002d0d20(void*, int);
    void FUN_002d0da0(void*, float, int);
};
namespace pure3d {

} // namespace pure3d
void pure3d::VertexAnimController::vfunc_7() {
    Track_2a6d10* track = (*(Animation_2a6d10 * *)&this->f_3c)->FUN_00288a10(0, 0x58545256, 0x544e49)->FUN_00288960();
    if (track) {
        int first, second;
        float firstTime, secondTime;
        void* firstData;
        void* secondData;
        track->FUN_00289f80(this->f_34, &first, &second);
        track->FUN_0028a080(first, &firstTime, &firstData);
        (*(Geometry_2a6d10 * *)&this->f_40)->FUN_002d0d20(firstData, 1);
        if (first != second) {
            track->FUN_0028a080(second, &secondTime, &secondData);
            (*(Geometry_2a6d10 * *)&this->f_40)->FUN_002d0da0(secondData, (this->f_34 - firstTime) / (secondTime - firstTime), track->count);
        }
    }
}
