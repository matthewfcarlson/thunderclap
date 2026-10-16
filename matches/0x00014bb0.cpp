#include "gen/global.h"

struct Z;
struct C_14bb0 {
    bool IsOk();
    Z* GetZ(int);
};
struct B_14bb0 {
    C_14bb0* GetC();
};
struct A_14bb0 {
    B_14bb0* GetB();
};
struct SoundObj_14bb0 {
    char pad[0x10];
    char data[0x40];
    char flag;
};
struct Out_14bb0 {
    void Send(C_14bb0*, void*);
    void Play(Z*, void*, float, int);
};
struct Mgr_14bb0 {
    char pad[0x34];
    Out_14bb0* out;
};
extern Mgr_14bb0* gMgr_14bb0;

bool CSoundAction::vfunc_7(int ) {
    C_14bb0* c = (*(A_14bb0 * *)&this->f_1c)->GetB()->GetC();
    if (!(*(SoundObj_14bb0 * *)&this->f_20)->flag) {
        gMgr_14bb0->out->Send(c, (*(SoundObj_14bb0 * *)&this->f_20)->data);
        return false;
    }
    if (c->IsOk()) {
        Z* z = c->GetZ(0);
        if (z)
            gMgr_14bb0->out->Play(z, (*(SoundObj_14bb0 * *)&this->f_20)->data, 100.0f, 0);
    }
    return false;
}
