class CActorManager {
  public:
    const char* Run(const char*);
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
};
class Method1 : public Function {
  public:
    virtual void v0();
    virtual void v2(CActorManager*, const char**, const char**);
    char pad[24];
    const char* (CActorManager::*fn)(const char*);
};
void Method1::v2(CActorManager* obj, const char** arg, const char** out) {
    const char* (CActorManager::*f)(const char*) = fn;
    const char* p = *arg;
    const char* r = (obj->*f)(p);
    if (out)
        *out = r;
}