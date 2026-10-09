extern void* __cdecl alloc(unsigned int);
extern int velocityVtable;
class VelocityXZAngleCondition {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    int x;
    int y;
    int z;
    float angle;
    void Init(int);
};
class Factory {
  public:
    VelocityXZAngleCondition* vfunc_5();
};
VelocityXZAngleCondition* Factory::vfunc_5() {
    VelocityXZAngleCondition* p = (VelocityXZAngleCondition*)alloc(0x14);
    if (p) {
        p->Init(0);
        *(int*)p = (int)&velocityVtable;
        p->z = 0;
        p->angle = 1.57079637f;
        return p;
    }
    return 0;
}