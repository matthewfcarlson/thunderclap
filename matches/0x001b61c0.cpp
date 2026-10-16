class CCollisionManager {
  public:
    void Method(float, float, float);
};
class Closure3 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, float*, int);
    char pad[24];
    void (CCollisionManager::*fn)(float, float, float);
    CCollisionManager* obj;
};
void Closure3::vfunc_2(int, float* p, int) {
    float* q = p;
    *(volatile int*)&p = *(int*)q;
    (obj->*fn)(*(float*)&p, q[1], q[2]);
}