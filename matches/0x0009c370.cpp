namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class CCameraManager {
  public:
    void fn(float, float, math::Vector, float);
};
class Closure4 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, float*, int);
    char pad[24];
    void (CCameraManager::*method)(float, float, math::Vector, float);
    CCameraManager* object;
};
void Closure4::vfunc_2(int unused, float* p, int unused2) {
    float a = *p++;
    float b = *p++;
    math::Vector v = *(math::Vector*)p;
    p += 3;
    float c = *p;
    (object->*method)(a, b, v, c);
}