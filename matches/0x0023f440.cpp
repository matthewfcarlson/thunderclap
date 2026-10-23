#include "gen/fight.h"

typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
class Ref {
  public:
    virtual void AddRef() throw();
    virtual void Release() throw();
};
namespace fight {
class Track_23f440 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void* vfunc_10(int, int, Ref*);
};
class Param_23f440 {};
class BreakPointActionBase {
  public:
    BreakPointActionBase() throw();
    virtual void v0();
    char pad[0x18];
};

class BreakPointAction_23f440 : public BreakPointActionBase {
  public:
    fight::BreakPointTrack* owner;
    Ref* ref;
    BreakPointAction_23f440(fight::BreakPointTrack* o, Ref* r) throw() : owner(o), ref(0) {
        if (r)
            r->AddRef();
        if (ref)
            ref->Release();
        ref = r;
    }
    virtual void v0();
};

} // namespace fight
int fight::BreakPointTrack::vfunc_10(int a, int b, int __p2) { Ref * r = (Ref *)__p2;

    return (int)(new BreakPointAction_23f440(this, r));
}
