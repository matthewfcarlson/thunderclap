class CSPManager {
  public:
    void Act(const char*, const char*, float, float, float);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class Closure5 : public Function {
  public:
    char pad[0x18];
    void (CSPManager::*fn)(const char*, const char*, float, float, float);
    CSPManager* obj;
    virtual void vfunc_2(void*, void*, void*);
};
void Closure5::vfunc_2(void* a, void* b, void* c) {
    char* p = (char*)b;
    const char* x = *(const char**)p;
    p += 4;
    const char* y = *(const char**)p;
    p += 4;
    float z = *(float*)p;
    p += 4;
    float w = *(float*)p;
    p += 4;
    float v = *(float*)p;
    (obj->*fn)(x, y, z, w, v);
}