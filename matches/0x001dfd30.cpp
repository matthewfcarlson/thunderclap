class CSPManager {
  public:
    int Fn(const char*, const char*);
};
struct Pair {
    const char* a;
    const char* b;
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class Method2 : public Function {
  public:
    char pad[0x18];
    int (CSPManager::*method)(const char*, const char*);
    virtual void vfunc_2(CSPManager* o, Pair* p, int* out);
};
void Method2::vfunc_2(CSPManager* o, Pair* p, int* out) {
    int (CSPManager::*fn)(const char*, const char*) = method;
    const char* a = p->a;
    const char* b = p->b;
    int r = (o->*fn)(a, b);
    if (out)
        *out = r;
}