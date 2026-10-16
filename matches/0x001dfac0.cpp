class CSPManager {
  public:
    void Act(const char*, bool);
};
struct Args {
    const char* s;
    bool b;
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
};
class Method2 : public Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(void*, Args*, void*);
    char pad[0x18];
    void (CSPManager::*method)(const char*, bool);
};
void Method2::v2(void* obj, Args* args, void*) {
    CSPManager* p = (CSPManager*)obj;
    (p->*method)(args->s, args->b);
}