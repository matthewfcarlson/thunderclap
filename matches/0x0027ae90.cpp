#include "gen/global.h"

class RDLFile_27ae90 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Ref_27ae90 {
  public:
    virtual void f0();
    virtual void f1();
};
void thunk_FUN_00267090(void*);

void RDLReader::vfunc_1() {
    if ((*(Ref_27ae90 * *)&this->f_04)) {
        (*(Ref_27ae90 * *)&this->f_04)->f1();
        (*(Ref_27ae90 * *)&this->f_04) = 0;
        if ((*(void * *)&this->f_08))
            thunk_FUN_00267090((*(void * *)&this->f_08));
    }
}
