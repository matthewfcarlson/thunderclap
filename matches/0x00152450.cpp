#include "gen/hulkfight.h"
#include "gen/owners.h"

struct H {
    void* next();
    void invoke(int, int);
};
struct HitThrowAction_nv_152450 {
    void finish();
};

void hulkfight::motion::HitThrowAction::vfunc_4() {
    H* x = (*(H * *)&this->f_20);
    void* p = ((void *)((owners::Object_592a0 *)x)->FUN_000592a0());
    H* q = (H*)p;
    p = q->next();
    if (p) {
        ((H*)p)->invoke(this->f_24, 0);
        ((HitThrowAction_nv_152450*)this)->finish();
    }
}
