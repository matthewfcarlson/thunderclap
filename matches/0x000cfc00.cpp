namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class HUDOverlay {
  public:
    void Show(math::Vector);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, math::Vector*, int);
};
class Method1 : public Function {
  public:
    char pad[0x18];
    void (HUDOverlay::*method)(math::Vector);
    HUDOverlay* obj;
};
class Closure1 : public Method1 {
  public:
    virtual void vfunc_2(int, math::Vector*, int);
};
void Closure1::vfunc_2(int, math::Vector* v, int) {
    (obj->*method)(*v);
}