class CScenarioManager {
  public:
    int method(float, const char*);
};
struct Args {
    float a;
    const char* b;
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Method2 : public Function {
    char pad[0x18];

  public:
    int (CScenarioManager::*fn)(float, const char*);
    virtual void vfunc_2(CScenarioManager* obj, Args* args, int* result);
};
void Method2::vfunc_2(CScenarioManager* obj, Args* args, int* result) {
    int (CScenarioManager::*f)(float, const char*) = fn;
    float a = args->a;
    const char* b = args->b;
    int r = (obj->*f)(a, b);
    if (result)
        *result = r;
}