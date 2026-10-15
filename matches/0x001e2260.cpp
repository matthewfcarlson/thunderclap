class CSPManager {
  public:
    bool invoke(float, float, float, float);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, float*, bool*);
};
class Closure4 : public Function {
  public:
    char pad[0x1c - 4];
    bool (CSPManager::*method)(float, float, float, float);
    CSPManager* obj;
    virtual void f2(void*, float*, bool*);
};
void Closure4::f2(void*, float* a, bool* result) {
    CSPManager* o = obj;
    bool (CSPManager::*m)(float, float, float, float) = method;
    float v0 = *a++;
    float v1 = *a++;
    float v2 = *a++;
    float v3 = *a++;
    bool r = (o->*m)(v0, v1, v2, v3);
    if (result)
        *result = r;
}