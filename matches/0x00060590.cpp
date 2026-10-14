extern const float gZero_60590;
class CMotionTrailTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float vfunc_7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    char pad[8];
    float a;
    float b;
    char pad2[0xb4];
    unsigned char flag;
};
float CMotionTrailTrack::vfunc_7() {
    if (flag)
        return b - a;
    return gZero_60590;
}