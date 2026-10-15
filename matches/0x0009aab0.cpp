class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class CCameraManager {
  public:
    void act(float, float, float, float);
};
class Method4 : public Function {
  public:
    virtual void f0();
    virtual void f2(CCameraManager*, float*, int);
    char pad[24];
    typedef void (CCameraManager::*M)(float, float, float, float);
    M method;
};
void Method4::f2(CCameraManager* obj, float* p, int unused) {
    float a = *p++;
    float b = *p++;
    float c = *p++;
    float d = *p++;
    (obj->*method)(a, b, c, d);
}