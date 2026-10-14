extern "C" char DAT_003f3390[];
extern "C" char DAT_003f34a0[];
class Obj_1adb0 {
  public:
    virtual void f();
    virtual void g();
};
class Action {
  public:
    Action();
    virtual void f();
    char pad[0x18];
    Obj_1adb0* mObj;
    int m20;
    int m24;
    char pad2[0x2c];
    int m54;
    int m58;
};
class Opportunity : public Action {
  public:
    Opportunity(int, Obj_1adb0*, int);
};
Opportunity::Opportunity(int p2, Obj_1adb0* p3, int p4) : Action() {
    *(unsigned long*)this = ((int)DAT_003f3390);
    mObj = 0;
    if (p3)
        p3->f();
    if (mObj)
        mObj->g();
    mObj = p3;
    m24 = p4;
    *(unsigned long*)this = ((int)DAT_003f34a0);
    m54 = 0;
    m58 = 0;
    m20 = p2;
}