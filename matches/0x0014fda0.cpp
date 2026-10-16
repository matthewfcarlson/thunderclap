#include "gen/hulkfight.h"

class Mid_14fda0 {
  public:
    Mid_14fda0* Touch();
    void Draw(float, int, int, int, int, unsigned char);
};
class Thing_14fda0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int d();
    char pad[0x48 - 4];
    int x48;
    int x4c;
    char p[0x78 - 0x50];
    float x78;
    int x7c;
    char p2[0x91 - 0x80];
    unsigned char x91;
};
class Ref_14fda0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual Thing_14fda0* d();
    Mid_14fda0* GetSub();
};

bool hulkfight::motion::HitDamageAction::vfunc_3(int , int ) {
    if ((*(Ref_14fda0 * *)&this->f_20)) {
        Thing_14fda0* t = (*(Ref_14fda0 * *)&this->f_20)->d();
        if (t) {
            Mid_14fda0* m = (*(Ref_14fda0 * *)&this->f_20)->GetSub()->Touch();
            m->Draw(*(float*)((char*)(*(void * *)&this->f_1c) + 0x10) * t->x78, t->x4c, t->x48, t->x7c, 0, t->x91);
        }
    }
    return (bool)(0);
}
