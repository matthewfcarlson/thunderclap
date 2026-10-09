class ChargeClearAction {
  public:
    char pad[0x1c];
    void* mObj;
    void* mNext;
    void vfunc_4();
};
struct A {
    char pad[0x14];
    unsigned char flag;
};
struct B {
    char pad[0x1e58];
    int value;
};
struct First {
    B* f();
};
struct Second {
    B* g();
};
void ChargeClearAction::vfunc_4() {
    if (!((A*)mObj)->flag) {
        B* x = ((First*)mNext)->f();
        B* y = ((Second*)x)->g();
        y->value = 0;
    }
}