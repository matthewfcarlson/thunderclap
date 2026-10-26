#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct Act_182000 {
    void Run(void* o, unsigned char b);
};
struct G_182000 {
    char pad[0x10];
    Act_182000* act;
};
extern G_182000* gG_182000;
struct Cfg_182000 {
    char pad[0x10];
    int idx;
    unsigned char b;
};
struct Ent_182000 {
    char pad[0x128];
    void* s128;
    void* Get(int i);
};
struct Reg2 {
    Ent_182000* Lookup();
};
struct Owner_182000 {
    Reg2* GetReg2();
};

bool hulkfight::motion::PropAddToCollisionAction::vfunc_5(hulk_intptr __p0, int q) { unsigned int p = (unsigned int)__p0;

    if (p == 0 && (*(Owner_182000 * *)&this->f_20) != 0) {
        Ent_182000* e = (*(Owner_182000 * *)&this->f_20)->GetReg2()->Lookup();
        int i = (*(Cfg_182000 * *)&this->f_1c)->idx;
        if (e) {
            void* o;
            if (i < 0)
                o = e->s128;
            else {
                if (i >= 8)
                    return false;
                o = e->Get(i);
            }
            if (o)
                gG_182000->act->Run(o, (*(Cfg_182000 * *)&this->f_1c)->b);
        }
    }
    return false;
}
