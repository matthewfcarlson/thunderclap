#include "gen/hulkfight.h"
#include "gen/owners.h"

struct A_171c60 {
};
struct B_171c60 {
    void* FUN_00059a30();
};

void hulkfight::motion::DriftToHulkAction::vfunc_4() {
    void* p = ((void *)((owners::Object_592a0 *)((*(A_171c60 * *)&this->f_20)))->FUN_000592a0());
    if (p) {
        p = ((B_171c60*)p)->FUN_00059a30();
        if (p)
            *(unsigned char*)((char*)p + 0x2140) = this->f_34;
    }
}
