// cl-flags: /O2 /GR /GX

namespace physics {
class Filter1D {
  public:
    virtual void vfunc_0();
    virtual float vfunc_1(float, float);
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

    virtual float vfunc_1(float param_2, float param_3);
};
} // namespace physics

extern const float ONE;

float physics::Kalmann1D::vfunc_1(float param_2, float param_3) {
    m8 = mC / (m10 + mC);
    mC = (ONE - m8) * mC + m14;
    m18 = (param_2 - m18) * m8 + param_3 * m4 + m18;
    return m18;
}