#include "gen/global.h"

class Manager {
  public:
    char pad[0x54];
    char flag;
    void Do(int, int, int);
};
class sSubtitleCallback_1c06f0 {
  public:
    virtual void vfunc_0(int, int);
    virtual void vfunc_1();
};

void sSubtitleManagerCallback::vfunc_0(int a, int b) {
    Manager* p = (*(Manager * *)&this->f_04);
    if (p) {
        if (!p->flag)
            p->Do(2, a, b);
        else
            p->Do(0, a, b);
    }
}
