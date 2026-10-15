class CCameraManager {
  public:
    void action(float, float, float, float);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method4 : public Function {
  public:
    char pad[24];
};
class Closure4 : public Method4 {
  public:
    typedef void (CCameraManager::*Fn)(float, float, float, float);
    Fn fn;
    CCameraManager* obj;
    virtual void vfunc_2(int, float*, int);
};
void Closure4::vfunc_2(int, float* p, int) {
    float a = *p++;
    float b = *p++;
    float c = *p++;
    float d = *p++;
    (obj->*fn)(a, b, c, d);
}