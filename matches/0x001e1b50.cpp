class CSPManager {
  public:
    void Fn(int, float, float, float);
};
class Function {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
};
class Method4 : public Function {
  public:
    char pad[24];
    void (CSPManager::*fn)(int, float, float, float);
    CSPManager* obj;
};
class Closure4 : public Method4 {
  public:
    virtual void A();
    virtual void B();
    virtual void C(int, const float*, int);
};
void Closure4::C(int x, const float* p, int y) {
    const int* q = (const int*)p;
    int a = *q++;
    volatile int b = *q++;
    int d = q[1];
    int c = q[0];
    (obj->*fn)(a, *(float*)&b, *(float*)&c, *(float*)&d);
}