#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Record_14ffc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void* f3();
};
class Helper_14ffc0 {
  public:
    void g();
};

bool hulkfight::motion::ClearFightParamsHitRecordAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    if ((*(Record_14ffc0 * *)&this->f_20)) {
        void* p = (*(Record_14ffc0 * *)&this->f_20)->f3();
        if (p) {
            ((Helper_14ffc0*)p)->g();
        }
    }
    return false;
}
