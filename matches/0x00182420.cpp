#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct Info_182420 {
    char p[0x10];
    int idx;
};
struct Hit_182420 {
    void Go();
};
struct Mgr_182420 {
    Hit_182420* Get(int i);
    void Play(int i, int a, int b, int c, int d, int e);
    char p[0x128];
    Hit_182420* def;
};
struct Sing {
    Mgr_182420* Find();
};
struct Tgt_182420 {
    Sing* GetSing();
};

bool hulkfight::motion::PropDestroyAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    if (!(*(Tgt_182420 * *)&this->f_20))
        return false;
    Mgr_182420* m = (*(Tgt_182420 * *)&this->f_20)->GetSing()->Find();
    int i = (*(Info_182420 * *)&this->f_1c)->idx;
    if (m) {
        Hit_182420* h;
        if (i < 0)
            h = m->def;
        else {
            if (i >= 8)
                return false;
            h = m->Get(i);
        }
        if (h) {
            m->Play(i, 0, -1, 0, 0, 0);
            h->Go();
        }
    }
    return false;
}
