namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class CCollisionManager {
  public:
    bool fn(math::Vector, int);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, void*, void*);
};
class Closure2 : public Function {
  public:
    char pad[0x18];
    typedef bool (CCollisionManager::*Method)(math::Vector, int);
    Method method;
    CCollisionManager* obj;
    virtual void vfunc_2(void*, void*, void*);
};
void Closure2::vfunc_2(void* unused, void* input, void* output) {
    CCollisionManager* target = obj;
    Method fn = method;
    math::Vector* v = (math::Vector*)input;
    bool r = (target->*fn)(*v, ((int*)input)[3]);
    if (output)
        *(bool*)output = r;
}
