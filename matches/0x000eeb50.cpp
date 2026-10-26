#include "gen/global.h"
#include "decls/data/game/global.h"

class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
inline void clearRef(Ref*& p) {
    Ref* q = p;
    if (q) {
        q->Release();
        p = 0;
    }
}

void FEThingsBase::vfunc_65() {
    if ((*(Ref**)&DAT_004de954)) {
        (*(Ref**)&DAT_004de954)->Release();
        (*(Ref**)&DAT_004de954) = 0;
    }
    Ref* p = (*(Ref * *)&this->f_17fc);
    if (p) {
        clearRef((*(Ref * *)&this->f_17fc));
        (*(Ref * *)&this->f_17fc) = 0;
    }
}
