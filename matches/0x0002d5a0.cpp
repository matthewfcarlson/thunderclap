namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class CActorManager {
  public:
    void act(math::Vector, float);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager*, void*, int);
};
struct Args {
    math::Vector v;
    float f;
};
class Method2 : public Function {
    char pad[0x18];

  public:
    void (CActorManager::*fn)(math::Vector, float);
    virtual void vfunc_2(CActorManager*, void*, int);
};
void Method2::vfunc_2(CActorManager* mgr, void* data, int unused) {
    Args* a = (Args*)data;
    (mgr->*fn)(a->v, a->f);
}