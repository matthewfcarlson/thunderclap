class HelperB_1719c0 {
  public:
    void* run();
};
class HelperA_1719c0 {
  public:
    HelperB_1719c0* run();
};
class ChargeClearAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual unsigned char vfunc_3(int, int);
    virtual void f4();
    virtual void f5();
    char pad[0x18];
    void* member1c;
    HelperA_1719c0* member20;
};
struct State_1719c0 {
    char pad[0x14];
    unsigned char active;
};
unsigned char ChargeClearAction::vfunc_3(int, int) {
    if (((State_1719c0*)member1c)->active) {
        HelperB_1719c0* x = member20->run();
        void* result = x->run();
        *(int*)((char*)result + 0x1e58) = 0;
        return 0;
    }
    return 1;
}