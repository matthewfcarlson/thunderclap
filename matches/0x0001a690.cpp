#include "gen/global.h"

struct Game_1a690 {
    bool Ready();
    void Go(int a, int b, int c);
    char pad[0x1b49];
    char f1b49;
    char pad2[0x2fe];
    int f1e48;
};
struct Sess {
    Game_1a690* Get();
};
struct Mid_1a690 {
    Game_1a690* Get();
};
struct Tgt_1a690 {
    void Fn(void*);
};
struct Ref_1a690 {
    virtual void v0();
    virtual void Release();
};
struct Info_1a690 {
    char pad[0x39];
    char flag;
};
Mid_1a690* __stdcall Conv();
struct Owner_1a690 {
    Mid_1a690* Get();
};
Sess* Lookup();

void CCollisionAction::vfunc_4() {
    Game_1a690* g = (*(Owner_1a690 * *)&this->f_1c)->Get()->Get();
    if ((*(Ref_1a690 * *)&this->f_3c)) {
        ((Tgt_1a690*)Conv())->Fn((*(Ref_1a690 * *)&this->f_3c));
        if ((*(Ref_1a690 * *)&this->f_3c)) {
            (*(Ref_1a690 * *)&this->f_3c)->Release();
            (*(Ref_1a690 * *)&this->f_3c) = 0;
        }
    }
    if ((*(Info_1a690 * *)&this->f_20)->flag) {
        if (g->Ready())
            g->Go(0, 0, 0);
    }
    g->f1b49 = 0;
    g->f1e48 = 0;
    if ((*(Ref_1a690 * *)&this->f_48)) {
        (*(Ref_1a690 * *)&this->f_48)->Release();
        (*(Ref_1a690 * *)&this->f_48) = 0;
    }
}
