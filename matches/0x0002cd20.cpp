class CActorManager {
  public:
    void Fn(const char*, bool);
};
struct Args {
    const char* name;
    bool flag;
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(CActorManager*, Args*, void*);
};
class Method2 : public Function {
  public:
    char pad[0x18];
    void (CActorManager::*method)(const char*, bool);
    virtual void v2(CActorManager* obj, Args* args, void* unused);
};
void Method2::v2(CActorManager* obj, Args* args, void* unused) {
    (obj->*method)(args->name, args->flag);
}
