#include "gen/global.h"

class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
extern Ref* gRef;
inline void clearRef(Ref*& p) {
    Ref* q = p;
    if (q) {
        q->Release();
        p = 0;
    }
}

void FEThingsBase::vfunc_65() {
    if (gRef) {
        gRef->Release();
        gRef = 0;
    }
    Ref* p = (*(Ref * *)&this->f_17fc);
    if (p) {
        clearRef((*(Ref * *)&this->f_17fc));
        (*(Ref * *)&this->f_17fc) = 0;
    }
}
