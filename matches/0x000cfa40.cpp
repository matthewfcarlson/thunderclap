namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class HUDOverlay {
  public:
    void Fn(const char*, float, float, math::Vector);
};
class Closure4 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, void*, void*);
    char pad[0x18];
    void (HUDOverlay::*method)(const char*, float, float, math::Vector);
    HUDOverlay* object;
};
void Closure4::vfunc_2(void* unused, void* args, void* extra) {
    char* p = (char*)args;
    const char* s = *(const char**)p;
    p += 4;
    float a = *(float*)p;
    p += 4;
    float b = *(float*)p;
    p += 4;
    math::Vector v = *(math::Vector*)p;
    (object->*method)(s, a, b, v);
}