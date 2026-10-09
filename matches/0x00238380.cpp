class RandomCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(int, int, float*);
    char pad[8];
    float value;
};
bool RandomCondition::vfunc_6(int a, int b, float* out) {
    if (out)
        *out += value;
    return true;
}