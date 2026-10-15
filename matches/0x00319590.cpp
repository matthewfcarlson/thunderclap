namespace physics {
class Filter1D {
  public:
    virtual bool vfunc_0(int, float, int);
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class SimpleFilter1D : public Filter1D {
  public:
    float scale;
    char pad[4];
    int value;
    int state;
    virtual bool vfunc_0(int, float, int);
};
bool SimpleFilter1D::vfunc_0(int v, float f, int) {
    value = v;
    if (f <= 0.0f)
        return false;
    state = 0;
    scale = 1.0f / f;
    return true;
}
} // namespace physics