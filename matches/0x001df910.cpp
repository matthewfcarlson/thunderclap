class CSPManager {
  public:
    bool fn(const char*, int);
};
struct Args {
    const char* s;
    int n;
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
};
class Method2 : public Function {
  public:
    virtual void v0();
    virtual void v2(CSPManager*, Args*, bool*);
    char pad[0x18];
    bool (CSPManager::*method)(const char*, int);
};
void Method2::v2(CSPManager* obj, Args* args, bool* out) {
    bool (CSPManager::*fn)(const char*, int) = method;
    const char* s = args->s;
    int n = args->n;
    bool value = (obj->*fn)(s, n);
    if (out)
        *out = value;
}