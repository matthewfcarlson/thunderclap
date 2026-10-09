class HelperB {
  public:
    void* run();
};
class HelperA {
  public:
    HelperB* run();
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
    HelperA* member20;
};
struct State {
    char pad[0x14];
    unsigned char active;
};
unsigned char ChargeClearAction::vfunc_3(int, int) {
    if (((State*)member1c)->active) {
        HelperB* x = member20->run();
        void* result = x->run();
        *(int*)((char*)result + 0x1e58) = 0;
        return 0;
    }
    return 1;
}