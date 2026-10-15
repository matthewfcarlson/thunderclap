namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class HUDOverlay {
  public:
    int go(int, math::Vector);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class Method2 : public Function {
  public:
    char pad[0x1c - 4];
    int (HUDOverlay::*fn)(int, math::Vector);
    void f2(HUDOverlay*, int*, int*);
};
void Method2::f2(HUDOverlay* obj, int* args, int* out) {
    int (HUDOverlay::*call)(int, math::Vector) = fn;
    int a = *args;
    math::Vector v = *(math::Vector*)++args;
    int r = (obj->*call)(a, v);
    if (out)
        *out = r;
}