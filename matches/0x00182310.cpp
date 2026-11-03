#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

struct Tgt_182310 {
    void G(int, int, int);
};
struct Ent_182310 {
    char pad[0x128];
    Tgt_182310* t128;
    int i12c;
};
struct Holder_182310 {
    Ent_182310* Find();
};
struct Src_182310 {
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

bool hulkfight::motion::PropDamageAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    if (!(*(Src_182310 * *)&this->f_20))
        return false;
    {
        Holder_182310* h = ((Holder_182310 *)((owners::Object_592a0 *)((*(Src_182310 * *)&this->f_20)))->FUN_000592a0());
        Ent_182310* e = h->Find();
        int i = (*(Cfg_182310 * *)&this->f_1c)->idx;
        if (e) {
            Tgt_182310* t;
            if (i < 0)
                t = e->t128;
            else if (i < 8)
                t = ((Tgt_182310 *)((owners::C_35ef0 *)e)->FUN_00035ef0((hulk_intptr)i));
            else
                return false;
            if (t)
                t->G((int)(*(Cfg_182310 * *)&this->f_1c)->f, e->i12c, 0);
        }
    }
    return false;
}
