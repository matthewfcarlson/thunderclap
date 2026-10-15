class CFMVManager {
  public:
    void Fn(float, float, float, float);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CFMVManager*, float*, void*);
};
class Method4 : public Function {
  public:
    char pad[0x18];
    void (CFMVManager::*fn)(float, float, float, float);
    virtual void vfunc_2(CFMVManager*, float*, void*);
};
void Method4::vfunc_2(CFMVManager* obj, float* p, void* b) {
    float f0 = *p++;
    float f1 = *p++;
    (obj->*fn)(f0, f1, p[0], p[1]);
}