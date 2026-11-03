#include "decls/data/game/global.h"

#include "compat/ptr.h"
// cl-flags: /O2 /GR /GX

namespace physics {
class Filter1D {
  public:
    virtual void vfunc_0();
    virtual hulk_freg vfunc_1(float, float);
    virtual void vfunc_2();
};

class Kalmann1D : public Filter1D {
  public:
    float m4;  // offset 0x4
    float m8;  // offset 0x8
    float mC;  // offset 0xC
    float m10; // offset 0x10
    float m14; // offset 0x14
    float m18; // offset 0x18

    virtual hulk_freg vfunc_1(float measurement, float control);
};
} // namespace physics


hulk_freg physics::Kalmann1D::vfunc_1(float measurement, float control) {
#if defined(__clang__)
    hulk_freg q = mC / (m10 + mC);
    m8 = q;
    mC = (DAT_003f32dc - q) * mC + m14;
    hulk_freg result = (measurement - m18) * m8 + control * m4 + m18;
    m18 = result;
    return result;
#else
    m8 = mC / (m10 + mC);
    mC = (DAT_003f32dc - m8) * mC + m14;
    m18 = (measurement - m18) * m8 + control * m4 + m18;
    return m18;
#endif
}