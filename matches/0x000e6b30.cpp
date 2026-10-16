#include "gen/global.h"

class Sub_e6b30 {
  public:
    void run(int);
};

void FEThingsBase::vfunc_17(int p) {
    if (p != (*(int *)&this->f_175c)) {
        this->f_1768 = p;
        if (p) {
            vfunc_27(p);
            this->f_17f8 = 2;
            this->f_176c = 2;
            if ((*(int *)&this->f_175c))
                ((Sub_e6b30*)(*(int *)&this->f_175c))->run(2);
        }
    }
}
