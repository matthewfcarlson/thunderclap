class Driver {
    char pad[1];
};
class JointDriver : public Driver {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual bool vfunc_11(int, int, int, int);
};
bool JointDriver::vfunc_11(int, int, int, int) {
    return false;
}