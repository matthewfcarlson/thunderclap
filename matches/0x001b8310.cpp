class CFMVManager {
  public:
    void Run(float, float, float, float);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, const float*, void*);
};
class Closure4 : public Function {
  public:
    char pad[0x18];
    void (CFMVManager::*fn)(float, float, float, float);
    CFMVManager* obj;
    virtual void vfunc_2(void*, const float*, void*);
};
void Closure4::vfunc_2(void* a, const float* p, void* b) {
    volatile int x = *(int*)p++;
    volatile int y = *(int*)p++;
    (obj->*fn)(*(float*)&x, *(float*)&y, *p, *(p + 1));
}