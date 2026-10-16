class CActorManager {
  public:
    bool Method(const char*, int);
};
class Function {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
};
class Method2 : public Function {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2(CActorManager*, void*, bool*);
    char pad[24];
    bool (CActorManager::*fn)(const char*, int);
};
void Method2::vfunc2(CActorManager* object, void* args, bool* out) {
    struct Args {
        const char* name;
        int id;
    };
    Args* a = (Args*)args;
    bool (CActorManager::*f)(const char*, int) = fn;
    const char* name = a->name;
    int id = a->id;
    bool result = (object->*f)(name, id);
    if (out)
        *out = result;
}