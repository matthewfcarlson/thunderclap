namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
struct Args {
    math::Vector v;
    float f;
};
class CCameraManager {
  public:
    void Action(math::Vector, float);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(CCameraManager*, const Args*, int);
};
class Method2 : public Function {
  public:
    char pad[0x18];
    void (CCameraManager::*fn)(math::Vector, float);
    virtual void f2(CCameraManager*, const Args*, int);
};
void Method2::f2(CCameraManager* obj, const Args* args, int unused) {
    (obj->*fn)(args->v, args->f);
}
