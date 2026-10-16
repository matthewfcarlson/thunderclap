#include "gen/fight.h"

class Reader_23a4d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(unsigned int*);
    virtual void v7(unsigned int*);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
};

bool fight::IFileStringReader::vfunc_6() {
    if (this->f_0d)
        return false;
    (*(Reader_23a4d0 * *)&this->f_08)->v21();
    unsigned int a;
    unsigned int b;
    (*(Reader_23a4d0 * *)&this->f_08)->v6(&a);
    (*(Reader_23a4d0 * *)&this->f_08)->v7(&b);
    (*(Reader_23a4d0 * *)&this->f_08)->v21();
    return a >= b;
}
