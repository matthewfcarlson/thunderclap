class SeqAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(int, char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    char pad[8];
    int low;
    int high;
    int clear;
    int init;
    char gap[4];
    int one;
};
void SeqAction::vfunc_2(int, char flag) {
    init = 100;
    one = 1;
    if (flag) {
        clear = 0;
        low = -1;
        high = -1;
    }
}