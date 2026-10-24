#include "gen/content.h"

#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042aee4[];
class Ref_266690 {
  public:
    virtual void A();
    virtual void Release();
};

void content::LoadRequest::FUN_00266690() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042aee4);
    if ((*(Ref_266690 * *)&this->f_18))
        (*(Ref_266690 * *)&this->f_18)->Release();
    if ((*(Ref_266690 * *)&this->f_124))
        (*(Ref_266690 * *)&this->f_124)->Release();
    if ((*(Ref_266690 * *)&this->f_1c))
        (*(Ref_266690 * *)&this->f_1c)->Release();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003f6098);
}
