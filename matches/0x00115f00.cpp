#include "gen/hulkfight.h"

class Obj_115f00 {
  public:
    void* FUN_000592a0();
    void* FUN_00059a30();
    void FUN_00036e70(void*, int);
};

void hulkfight::ai::MotionClosestWaypointAction::vfunc_4() {
    if ((*(Obj_115f00 * *)&this->f_20)) {
        void* a = (*(Obj_115f00 * *)&this->f_20)->FUN_000592a0();
        a = ((Obj_115f00*)a)->FUN_00059a30();
        if (a) {
            *(unsigned char*)((char*)a + 0x2140) = this->f_58;
            *((unsigned char*)a + 0x2149) = 0;
            ((Obj_115f00*)a)->FUN_00036e70((char*)this + 0x60, 0);
        }
    }
}
