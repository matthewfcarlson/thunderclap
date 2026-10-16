class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class CAmbientsManager {
  public:
    void invoke(const char*, bool);
};
class Method2 : public Function {
  public:
    char pad[0x18];
    void (CAmbientsManager::*fn)(const char*, bool);
    virtual void vfunc_2(CAmbientsManager*, void*, void*);
};
void Method2::vfunc_2(CAmbientsManager* obj, void* args, void* unused) {
    struct Args {
        const char* s;
        bool b;
    };
    Args* a = (Args*)args;
    (obj->*fn)(a->s, a->b);
}