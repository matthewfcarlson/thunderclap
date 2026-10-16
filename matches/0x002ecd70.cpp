namespace physics {
class SimCGSValue {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(float);
    virtual void vfunc_2();
    virtual void vfunc_3();
    float a;
    float b;
};
class SimUnits {};
class SimTime : public SimCGSValue, public SimUnits {
  public:
    virtual void vfunc_1(float);
};
void SimTime::vfunc_1(float x) {
    b = x;
    a = x;
}
} // namespace physics