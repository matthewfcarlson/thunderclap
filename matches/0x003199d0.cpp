class Sub_3199d0 {
  public:
    virtual void Fn(float a, float b, float c);
};
class K_3199d0 {
  public:
    virtual bool Init(float a, float b, float c);
    int pad4;
    char p8[4];
    float m0c;
    float m10;
    float m14;
    float m18;
    Sub_3199d0 sub;
    char p20[0x18];
    float m38;
};
bool K_3199d0::Init(float a, float b, float c) {
    m18 = a;
    m10 = b * b;
    float v = c * c;
    m14 = v;
    if (!(v > 0.0f))
        v = 1.0f;
    m0c = v;
    pad4 = 0;
    (&sub)->Fn(a, b, c);
    m38 = a;
    return true;
}
