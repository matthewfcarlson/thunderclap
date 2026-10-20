#include "compat/ptr.h"
extern "C" char DAT_00415ad0[];
class Base_15c0c0 {
  public:
    void Fin();
};
class Member_15c0c0 {
  public:
    void Rel();
    int pad[2];
};
class GrappleLocomotionSteerTrack {
  public:
    void Kill();
    hulk_intptr vf;
    char pad[0x14];
    Member_15c0c0 a;
    Member_15c0c0 b;
    Member_15c0c0 c;
    Member_15c0c0 d;
    Member_15c0c0 e;
};
void GrappleLocomotionSteerTrack::Kill() {
    vf = ((hulk_intptr)DAT_00415ad0);
    e.Rel();
    d.Rel();
    c.Rel();
    b.Rel();
    a.Rel();
    ((Base_15c0c0*)this)->Fin();
}
