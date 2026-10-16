class CScenarioManager {
  public:
    int Run(const char*);
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
class Method1 : public Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(CScenarioManager*, const char**, int*);
    char pad[0x18];
    int (CScenarioManager::*fn)(const char*);
};
void Method1::v2(CScenarioManager* obj, const char** arg, int* out) {
    int (CScenarioManager::*f)(const char*) = fn;
    const char* a = *arg;
    int r = (obj->*f)(a);
    if (out)
        *out = r;
}