#include "decls/data/game/unknown.h"
// data: gOwner = DAT_004e370c

struct Mgr_1ef800 {
    void Set(int n);
};

struct Owner_1ef800 {
    char pad[4];
    Mgr_1ef800* mgr;
};


class CSoundCommand {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int a, int b);
};

class CSoundCommand_ReturnToDefaultMix : public CSoundCommand {
  public:
    char pad[0xc];
    float mValue;
    virtual void vfunc_1(int a, int b);
};

void CSoundCommand_ReturnToDefaultMix::vfunc_1(int a, int b) {
    (*(Owner_1ef800**)&DAT_004e370c)->mgr->Set((int)(__int64)mValue);
}
