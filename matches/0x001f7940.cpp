class CEffectManager {
  public:
    unsigned int Do(char*, float, float);
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(CEffectManager*, void*, unsigned int*);
};
class Method3 : public Function {
  public:
    char pad[0x18];
    unsigned int (CEffectManager::*method)(char*, float, float);
    virtual void v2(CEffectManager* obj, void* args, unsigned int* result);
};
void Method3::v2(CEffectManager* obj, void* args, unsigned int* result) {
    struct Args {
        char* a;
        float b;
        float c;
    };
    Args* p = (Args*)args;
    unsigned int (CEffectManager::*fn)(char*, float, float) = method;
    char* a = p->a;
    float b = p->b;
    float c = p->c;
    unsigned int r = (obj->*fn)(a, b, c);
    if (result)
        *result = r;
}