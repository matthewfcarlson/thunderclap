class CScenarioManager {
  public:
    int SetState(int);
};
class Arg {
  public:
    int value;
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(CScenarioManager*, Arg*, int*);
};
class Method1 : public Function {
  public:
    char pad[0x18];
    int (CScenarioManager::*method)(int);
    void f2(CScenarioManager*, Arg*, int*);
};
void Method1::f2(CScenarioManager* obj, Arg* arg, int* out) {
    int (CScenarioManager::*fn)(int) = method;
    int v = arg->value;
    int r = (obj->*fn)(v);
    if (out)
        *out = r;
}