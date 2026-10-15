namespace physics {
class Filter1D {
  public:
    virtual bool vfunc_0(int, float, float);
    virtual void vfunc_1();
    virtual void vfunc_2();
    int a;
    int pad;
    float b, c, d;
    int e;
};
class Kalmann1D : public Filter1D {
  public:
    bool vfunc_0(int, float, float);
};
bool Kalmann1D::vfunc_0(int x, float y, float z) {
    e = x;
    c = y * y;
    d = z * z;
    b = d > 0.0f ? d : 1.0f;
    a = 0;
    return true;
}
} // namespace physics