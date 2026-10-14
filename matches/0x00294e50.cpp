const float zero_294e50 = 0.0f;
class TextureFont {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual float vfunc_10(short*);
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual float vfunc_18(short*);
    virtual void f19();
};
float TextureFont::vfunc_10(short* s) {
    if (!s)
        return zero_294e50;
    float best = 0.0f;
    int i = 0;
    while (s[i] != 0) {
        float v = vfunc_18(s + i);
        if (v > best)
            best = v;
        short c = s[i];
        while (c != 0 && c != 10) {
            ++i;
            c = s[i];
        }
        if (s[i] == 10)
            ++i;
    }
    return best;
}