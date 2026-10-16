#include "gen/global.h"

class Result_16650 {
  public:
    void finish(int);
};
struct CMotionTrailAction_nv_16650 {
    Result_16650* first();
};

void CMotionTrailAction::vfunc_4() {
    Result_16650* r = ((CMotionTrailAction_nv_16650*)this)->first();
    char* p = (char*)(*(void * *)&this->f_20);
    if (p[0xc8])
        r->finish(this->f_24);
}
