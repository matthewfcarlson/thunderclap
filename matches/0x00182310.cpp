#include "gen/hulkfight.h"

struct Tgt_182310 {
    void G(int, int, int);
};
struct Ent_182310 {
    char pad[0x128];
    Tgt_182310* t128;
    int i12c;
    Tgt_182310* Get(int);
};
struct Holder_182310 {
    Ent_182310* Find();
};
struct Src_182310 {
    Holder_182310* Hld();
};
struct Cfg_182310 {
    char pad[0x10];
    int idx;
    float f;
};
class Action_182310 {
  public:
    virtual void a();
    virtual void b();
    virtual bool vfunc_2();
};

bool hulkfight::motion::PropDamageAction::vfunc_3(int , int ) {
    if (!(*(Src_182310 * *)&this->f_20))
        return false;
    {
        Holder_182310* h = (*(Src_182310 * *)&this->f_20)->Hld();
        Ent_182310* e = h->Find();
        int i = (*(Cfg_182310 * *)&this->f_1c)->idx;
        if (e) {
            Tgt_182310* t;
            if (i < 0)
                t = e->t128;
            else if (i < 8)
                t = e->Get(i);
            else
                return false;
            if (t)
                t->G((int)(*(Cfg_182310 * *)&this->f_1c)->f, e->i12c, 0);
        }
    }
    return false;
}
