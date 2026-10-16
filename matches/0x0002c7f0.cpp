class CActorManager {
  public:
    bool action(const char*);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager*, const char**, bool*);
};
class Method1 : public Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_2(CActorManager*, const char**, bool*);
    char pad[0x18];
    bool (CActorManager::*method)(const char*);
};
void Method1::vfunc_2(CActorManager* obj, const char** arg, bool* out) {
    bool (CActorManager::*fn)(const char*) = method;
    const char* val = *arg;
    bool r = (obj->*fn)(val);
    if (out)
        *out = r;
}
