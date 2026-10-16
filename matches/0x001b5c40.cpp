class CCollisionManager {
  public:
    void Run(float, float, float);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CCollisionManager*, float*, int);
};
class Method3 : public Function {
  public:
    char pad[24];
    void (CCollisionManager::*fn)(float, float, float);
    virtual void vfunc_2(CCollisionManager*, float*, int);
};
void Method3::vfunc_2(CCollisionManager* obj, float* args, int unused) {
    float* p = args;
    *(volatile int*)&args = *(int*)p;
    (obj->*fn)(*(float*)&args, p[1], p[2]);
}