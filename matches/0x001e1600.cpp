class CSPManager {
  public:
    int Fn(const char*);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class Closure1 : public Function {
  public:
    char pad[0x18];
    int (CSPManager::*fn)(const char*);
    CSPManager* obj;
    virtual void vfunc_2(int unused, const char** arg, int* out);
};
void Closure1::vfunc_2(int unused, const char** arg, int* out) {
    CSPManager* o = obj;
    int (CSPManager::*f)(const char*) = fn;
    int r = (o->*f)(*arg);
    if (out)
        *out = r;
}