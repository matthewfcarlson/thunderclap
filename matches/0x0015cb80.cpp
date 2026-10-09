class A {
  public:
    int first();
};
class B {
  public:
    int second();
    void third(int);
};
class LocomotingAction {
  public:
    char pad[0x18];
    A* mObject;
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(void*, void*);
    virtual void f4();
    virtual void f5();
};
bool LocomotingAction::vfunc_3(void*, void*) {
    int x;
    if (mObject == 0)
        return false;
    x = mObject->first();
    if (x == 0)
        return false;
    x = ((B*)x)->second();
    if (x == 0)
        return false;
    ((B*)x)->third(1);
    return true;
}
