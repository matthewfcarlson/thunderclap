namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class HUDOverlay {
  public:
    void Action(math::Vector);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Method1 : public Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_2(HUDOverlay*, math::Vector*, int);
    char pad[24];
    void (HUDOverlay::*method)(math::Vector);
};
void Method1::vfunc_2(HUDOverlay* o, math::Vector* v, int) {
    (o->*method)(*v);
}