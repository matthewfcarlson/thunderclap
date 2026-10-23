#include "gen/hulkfight.h"

class Track_14ad10 {
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
    virtual int v10(int, int, int);
};
class Param_14ad10 {};
class GrappleHitReactionAction_14ad10 {
  public:
    int Init(hulkfight::motion::GrappleHitReactionTrack*, int);
};
extern int GetParam(int);
extern GrappleHitReactionAction_14ad10* Allocate(int);

int hulkfight::motion::GrappleHitReactionTrack::vfunc_10(int a, int b, int c) {
    int x = GetParam(c);
    if (x) {
        GrappleHitReactionAction_14ad10* p = Allocate(0x58);
        if (p)
            return p->Init(this, x);
    }
    return 0;
}
