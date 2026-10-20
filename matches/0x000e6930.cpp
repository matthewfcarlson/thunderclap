// FEThingsBase::vfunc_30 @ 0x000e6930
#include "gen/global.h"

#include "decls/data/game/global.h"

class Item_e6930 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void Activate();   // slot 14
    virtual void Deactivate(); // slot 15
};

class Source_e6930 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
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
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual int GetValue();    // slot 35
};

void FEThingsBase::vfunc_30() {
    if ((*(Item_e6930 * *)&this->f_1760) != 0)
        (*(Item_e6930 * *)&this->f_1760)->Deactivate();
    (*(Item_e6930 * *)&this->f_1760) = (*(Item_e6930 * *)&this->f_183c);
    (*(Item_e6930 * *)&this->f_183c) = 0;
    if ((*(Item_e6930 * *)&this->f_1760) != 0) {
        (*(Item_e6930 * *)&this->f_1760)->Activate();
    } else if ((*(Source_e6930 * *)&this->f_175c) != 0) {
        vfunc_40((*(Source_e6930 * *)&this->f_175c)->GetValue());
    }
    this->f_1838 = 0;
    this->f_1834 = 0;
    this->f_1830 = 1;
    DAT_004de94c = 0;
}
