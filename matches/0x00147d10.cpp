#include "compat/ptr.h"
namespace fight {
class Track {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual int f8(int, int);
};
class Param {};
} // namespace fight
extern "C" int __cdecl helper(hulk_intptr);
namespace hulkfight {
namespace motion {
class GrappleHitReactionTrack : public fight::Track, public fight::Param {
  public:
    virtual int vfunc_8(int a, int b);
};
int GrappleHitReactionTrack::vfunc_8(int a, int b) {
    return helper(b);
}
} // namespace motion
} // namespace hulkfight