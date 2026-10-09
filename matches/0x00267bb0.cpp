class TimerList {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[8];
    int mRefCount;
};
void TimerList::f1() {
    if (--mRefCount == 0)
        f2(1);
}