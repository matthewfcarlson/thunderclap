class CWorldStreamManager {
  public:
    bool Work(int);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class Method1 : public Function {
  public:
    virtual void f0();
    virtual void f2(CWorldStreamManager*, int*, bool*);
    char pad[24];
    bool (CWorldStreamManager::*fn)(int);
};
void Method1::f2(CWorldStreamManager* obj, int* arg, bool* out) {
    bool (CWorldStreamManager::*f)(int) = fn;
    int value = *arg;
    bool result = (obj->*f)(value);
    if (out)
        *out = result;
}