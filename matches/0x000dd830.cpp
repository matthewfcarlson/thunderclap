struct Block_dd830 {
    unsigned long x[10];
};
struct Other_dd830 {
    virtual void f0();
    virtual void f1(void*, void*);
};
class ControllerState {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    void* a;
    Other_dd830* b;
    unsigned long* src;
    unsigned long* dst;
};
void ControllerState::vfunc_2() {
    *reinterpret_cast<Block_dd830*>(dst) = *reinterpret_cast<Block_dd830*>(src);
    b->f1(a, src);
}