class CPatrolPathManager {
  public:
    bool Find(const char*);
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
};
class Method1 : public Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void vfunc_2(CPatrolPathManager*, const char**, bool*);
    char pad[0x18];
    bool (CPatrolPathManager::*fn)(const char*);
};
void Method1::vfunc_2(CPatrolPathManager* obj, const char** arg, bool* out) {
    bool (CPatrolPathManager::*f)(const char*) = fn;
    const char* x = *arg;
    bool r = (obj->*f)(x);
    if (out)
        *out = r;
}