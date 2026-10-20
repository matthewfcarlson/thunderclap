struct CSPManager {
    bool Invoke(const char*, float, float, int);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(void*, void*, void*);
};
class Closure4 : public Function {
  public:
    char pad[0x18];
    bool (CSPManager::*fn)(const char*, float, float, int);
    CSPManager* volatile obj;
    virtual void vfunc_2(void*, void*, void*);
};
void Closure4::vfunc_2(void*, void* p, void* out) {
    CSPManager* o = obj;
    bool (CSPManager::*f)(const char*, float, float, int) = fn;
    unsigned* a = (unsigned*)p;
    const char* s = (const char*)*a++;
    float x = *(float*)a++;
    float y = *(float*)a++;
    int n = *a++;
    bool r = (o->*f)(s, x, y, n);
    if (out)
        *(bool*)out = r;
}