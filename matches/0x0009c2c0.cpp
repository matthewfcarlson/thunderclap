class CCameraManager {
  public:
    void Fn(float, float, float, float, float, float);
};
class Function {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
};
class Closure6 : public Function {
  public:
    char pad[0x18];
    void (CCameraManager::*fn)(float, float, float, float, float, float);
    CCameraManager* obj;
    virtual void vfunc_2(int, float*, int);
};
void Closure6::vfunc_2(int, float* p, int) {
    volatile float* q = p;
    float a = *q++;
    float b = *q++;
    float c = *q++;
    float d = *q++;
    float e = ((float*)q)[0], f = ((float*)q)[1];
    (obj->*fn)(a, b, c, d, e, f);
}