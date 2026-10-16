class CUnlockablesManager {
  public:
    void Unlock(int, bool);
};
struct Args {
    int n;
    bool b;
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CUnlockablesManager*, Args*, void*);
};
class Method2 : public Function {
  public:
    char pad[0x18];
    void (CUnlockablesManager::*fn)(int, bool);
    virtual void vfunc_2(CUnlockablesManager*, Args*, void*);
};
void Method2::vfunc_2(CUnlockablesManager* obj, Args* args, void* result) {
    (obj->*fn)(args->n, args->b);
}