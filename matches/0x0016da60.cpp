class ConditionFactory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
namespace hulkfight {
namespace motion {
class VelocityAnimatedYCondition {
  public:
    void Init(int);
    int vptr;
    int m4;
    int m8;
    int mC;
    int m10;
};
} // namespace motion
} // namespace hulkfight
extern void* __cdecl alloc(unsigned int);
class Factory : public ConditionFactory {
  public:
    void* vfunc_5();
};
void* Factory::vfunc_5() {
    hulkfight::motion::VelocityAnimatedYCondition* p =
        (hulkfight::motion::VelocityAnimatedYCondition*)alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = 0x4167f8;
        p->mC = 0;
        p->m10 = 0;
        return p;
    }
    return 0;
}