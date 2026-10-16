#include "gen/hulkfight.h"

struct A_171c60 {
    void* FUN_000592a0();
};
struct B_171c60 {
    void* FUN_00059a30();
};

void hulkfight::motion::DriftToHulkAction::vfunc_4() {
    void* p = (*(A_171c60 * *)&this->f_20)->FUN_000592a0();
    if (p) {
        p = ((B_171c60*)p)->FUN_00059a30();
        if (p)
            *(unsigned char*)((char*)p + 0x2140) = this->f_34;
    }
}
