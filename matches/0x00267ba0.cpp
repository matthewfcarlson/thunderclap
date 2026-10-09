class TimerList {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad[8];
    int value;
};
void TimerList::vfunc_0() {
    ++value;
}