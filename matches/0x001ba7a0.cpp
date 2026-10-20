struct CRenderManager {
    unsigned int run(unsigned int, const char*, float, float);
};
class Closure4 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, void*, void*);
    char pad[0x18];
    unsigned int (CRenderManager::*method)(unsigned int, const char*, float, float);
    CRenderManager* obj;
};
void Closure4::vfunc_2(void*, void* p, void* out) {
    CRenderManager* o = obj;
    unsigned int (CRenderManager::*fn)(unsigned int, const char*, float, float) = method;
    unsigned int* a = (unsigned int*)p;
    unsigned int id = *a++;
    const char* volatile name = (const char*)*a++;
    float first = *(float*)a++;
    float second = *(float*)a++;
    unsigned int value = (o->*fn)(id, name, first, second);
    if (out)
        *(unsigned int*)out = value;
}