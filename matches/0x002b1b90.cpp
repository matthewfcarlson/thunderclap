#include "gen/pure3d.h"

class Node_2b1b90 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void update(int);
};

void pure3d::MultiController::vfunc_16(int p) {
    if (this->f_3c != p) {
        this->f_3c = p;
        for (unsigned int i = 0; i < (unsigned int)this->f_44; i++)
            (*(Node_2b1b90 ** *)&this->f_48)[i]->update(p);
        this->f_34 = vfunc_20();
        int r;
        if (this->f_3c != 3 && this->f_3c != 5)
            r = 1;
        else
            r = 0;
        (*(unsigned char *)&this->f_40) = (unsigned char)r;
    }
}
