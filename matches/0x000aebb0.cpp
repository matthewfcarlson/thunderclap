class Function {
  public:
    virtual void v0();
    virtual void v1();
};
struct Args {
    int a;
    bool b;
};
class CControllerManager {
  public:
    void fn(int, bool);
};
class Method2 : public Function {
  public:
    virtual void v0();
    virtual void v2(CControllerManager*, Args*, int);
    char pad[0x18];
    void (CControllerManager::*method)(int, bool);
};
void Method2::v2(CControllerManager* obj, Args* args, int) {
    (obj->*method)(args->a, args->b);
}