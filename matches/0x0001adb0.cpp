class Obj {
  public:
    virtual void f();
    virtual void g();
};
class Action {
  public:
    Action();
    virtual void f();
    char pad[0x18];
    Obj* mObj;
    int m20;
    int m24;
    char pad2[0x2c];
    int m54;
    int m58;
};
class Opportunity : public Action {
  public:
    Opportunity(int, Obj*, int);
};
Opportunity::Opportunity(int p2, Obj* p3, int p4) : Action() {
    *(unsigned long*)this = 0x3f3390;
    mObj = 0;
    if (p3)
        p3->f();
    if (mObj)
        mObj->g();
    mObj = p3;
    m24 = p4;
    *(unsigned long*)this = 0x3f34a0;
    m54 = 0;
    m58 = 0;
    m20 = p2;
}