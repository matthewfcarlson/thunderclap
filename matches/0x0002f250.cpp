namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class CActorManager {
  public:
    bool Action(math::Vector);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class Closure1 : public Function {
  public:
    char pad[0x18];
    bool (CActorManager::*method)(math::Vector);
    CActorManager* obj;
    virtual void vfunc_2(int unused, const math::Vector* v, bool* out);
    inline bool invoke(math::Vector v) {
        CActorManager* o = obj;
        bool (CActorManager::*fn)(math::Vector) = method;
        return (o->*fn)(v);
    }
};
void Closure1::vfunc_2(int unused, const math::Vector* v, bool* out) {
    math::Vector copy = *v;
    bool result = invoke(copy);
    if (out)
        *out = result;
}