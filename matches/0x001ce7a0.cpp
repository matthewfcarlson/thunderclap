class CScenarioManager {
  public:
    int run(const char*);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, void*, int*);
};
class Method1 : public Function {
  public:
    char pad[0x18];
    int (CScenarioManager::*fn)(const char*);
    CScenarioManager* obj;
};
class Closure1 : public Method1 {
  public:
    virtual void vfunc_2(void*, void*, int*);
};
void Closure1::vfunc_2(void*, void* args, int* out) {
    CScenarioManager* o = obj;
    int (CScenarioManager::*f)(const char*) = fn;
    int r = (o->*f)(*(const char**)args);
    if (out)
        *out = r;
}