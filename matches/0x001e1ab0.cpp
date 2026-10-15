class CSPManager {
  public:
    bool invoke(const char*, const char*, int, float, const char*);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, void*, void*);
};
class Closure5 : public Function {
  public:
    char pad[0x18];
    bool (CSPManager::*fn)(const char*, const char*, int, float, const char*);
    CSPManager* obj;
    virtual void f2(void*, void*, void*);
};
void Closure5::f2(void* unused, void* args, void* result) {
    CSPManager* p = obj;
    bool (CSPManager::*method)(const char*, const char*, int, float, const char*) = fn;
    void** a = (void**)args;
    const char* s1 = (const char*)*a++;
    const char* s2 = (const char*)*a++;
    int n = (int)*a++;
    float v = *(float*)a++;
    const char* s3 = (const char*)*a;
    bool r = (p->*method)(s1, s2, n, v, s3);
    if (result)
        *(bool*)result = r;
}