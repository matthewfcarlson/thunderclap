extern const float gEps;
extern const float gNeg;
union Bits {
    float f;
    unsigned long u;
};
inline float Abs(float v) {
    Bits b;
    b.f = v;
    b.u &= 0x7fffffffUL;
    return b.f;
}
struct Sub {
    char pad[0x14];
    float m14;
};
class Cls {
  public:
    float Fn();
    char pad0[0x20];
    Sub* m20;
    char pad1[0x204];
    float m228, m22c, m230;
};
float Cls::Fn() {
    float calc;
    if (Abs(m228) <= gEps)
        return gNeg;
    if (Abs(m20->m14) <= gEps)
        return gNeg;
    return Abs((m230 - m22c) / (m20->m14 * m228));
}
