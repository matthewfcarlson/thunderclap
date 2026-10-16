// Same code shape as 0x000b3ef0 (propagated; names are from that function)
#include "gen/global.h"

class Ref_1fad80 {
  public:
    virtual void A();
    virtual void Release();
};

void MyFileStream::vfunc_2() {
    if ((*(Ref_1fad80 * *)&this->f_04)) {
        (*(Ref_1fad80 * *)&this->f_04)->Release();
        (*(Ref_1fad80 * *)&this->f_04) = 0;
    }
}
