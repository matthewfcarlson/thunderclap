#include "compat/ptr.h"
extern "C" char DAT_003f3390[];
extern "C" char DAT_003f3ce0[];
class Arg_20b50 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class CAction {
  public:
    CAction();
    hulk_intptr vf;
    char pad[0x18];
    Arg_20b50* mArg;
};
class CDeathAction : public CAction {
  public:
    CDeathAction(Arg_20b50*);
};
CDeathAction::CDeathAction(Arg_20b50* a) {
    vf = ((hulk_intptr)DAT_003f3390);
    mArg = 0;
    if (a)
        a->AddRef();
    if (mArg)
        mArg->Release();
    mArg = a;
    vf = ((hulk_intptr)DAT_003f3ce0);
}
