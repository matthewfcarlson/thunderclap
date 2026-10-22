class CDisplayEffect_dee40 {
  public:
    CDisplayEffect_dee40() {
        a = 0;
        b = 0;
    }
    int a;
    int b;
};
class CDropShadowDisplayEffect : public CDisplayEffect_dee40 {
  public:
    CDropShadowDisplayEffect();
    virtual void f();
    float c;
    unsigned int d;
};
CDropShadowDisplayEffect::CDropShadowDisplayEffect() {
    c = 0.1f;
    d = 0xff000000;
}
