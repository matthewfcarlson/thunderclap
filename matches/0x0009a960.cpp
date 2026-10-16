class CCameraManager {
  public:
    void Do(float, float, bool);
};
struct Args {
    float a, b;
    bool c;
};
class Function {
  public:
    virtual void F0();
    virtual void F1();
};
class Method3 : public Function {
  public:
    virtual void F0();
    virtual void F2(CCameraManager*, Args*, int);
    char pad[24];
    void (CCameraManager::*method)(float, float, bool);
};
void Method3::F2(CCameraManager* obj, Args* args, int unused) {
    Args* p = args;
    *(volatile float*)&args = p->a;
    (obj->*method)(*(float*)&args, p->b, p->c);
}