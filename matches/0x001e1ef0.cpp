class CSPManager {
  public:
    void Fn(const char*, int, float, float, float, float);
};
class Closure6 {
  public:
    virtual void a();
    virtual void b();
    virtual void vfunc_2(int, const unsigned int*, int);
    char pad[24];
    void (CSPManager::*method)(const char*, int, float, float, float, float);
    CSPManager* obj;
};
void Closure6::vfunc_2(int, const unsigned int* p, int) {
    const char* a = (const char*)*p++;
    int b = *p++;
    float c = *(float*)p++;
    float d = *(float*)p++;
    float e = *(float*)p++;
    float f = *(float*)p++;
    (obj->*method)(a, b, c, d, e, f);
}