class A_1710a0 {
  public:
    void* f();
};
class B_1710a0 {
  public:
    void* g();
};
class C_1710a0 {
  public:
    void h(int);
};
class MotionStateAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual bool vfunc_5(int, int);
    char pad[0x18];
    void* mOne;
    A_1710a0* mTwo;
};
bool MotionStateAction::vfunc_5(int param_2, int unused) {
    if (param_2 == 0) {
        void* a = mTwo->f();
        void* b = ((B_1710a0*)a)->g();
        ((C_1710a0*)b)->h(*(int*)((char*)mOne + 0x14));
    }
    return true;
}