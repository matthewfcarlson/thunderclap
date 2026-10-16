#include "gen/core.h"

unsigned int GetTime();
class Pad_269170 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Ready();
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
    virtual void Update(unsigned int t);
    char pad[0x49e - 4];
    bool mActive;
    char pad2[1];
};
struct ControllerSystemXBox_nv_269170 {
    void Poll();
};

void core::ControllerSystemXBox::vfunc_12() {
    unsigned int now = GetTime();
    if (now - this->f_12a4 >= (*(unsigned int *)&this->f_12a0)) {
        this->f_12a4 = now;
        ((ControllerSystemXBox_nv_269170*)this)->Poll();
        for (int i = 0; i < 4; i++) {
            if ((*(Pad_269170 (*)[4])&this->f_20)[i].mActive && (*(Pad_269170 (*)[4])&this->f_20)[i].Ready())
                (*(Pad_269170 (*)[4])&this->f_20)[i].Update((*(unsigned int *)&this->f_14) + now);
        }
        if (!(*(bool *)&this->f_10))
            vfunc_8(GetTime());
    }
}
