class CPatrolPathManager {
  public:
    bool invoke(const char*, bool, int);
};
struct Args_106a40 {
    const char* s;
    bool b;
    int i;
};
typedef bool (CPatrolPathManager::*Fn_106a40)(const char*, bool, int);
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method3 : public Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual bool f2(int x, Args_106a40* a, bool* out);
    char pad[0x1c - 4];
    Fn_106a40 fn;
};
bool Method3::f2(int x, Args_106a40* a, bool* out) {
    Fn_106a40 f = fn;
    const char* s = a->s;
    bool b = a->b;
    int i = a->i;
    bool r = (((CPatrolPathManager*)x)->*f)(s, b, i);
    if (out)
        *out = r;
    return r;
}
