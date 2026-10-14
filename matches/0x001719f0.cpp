class ChargeClearAction {
  public:
    char pad[0x1c];
    void* mObj;
    void* mNext;
    void vfunc_4();
};
struct A_1719f0 {
    char pad[0x14];
    unsigned char flag;
};
struct B_1719f0 {
    char pad[0x1e58];
    int value;
};
struct First_1719f0 {
    B_1719f0* f();
};
struct Second_1719f0 {
    B_1719f0* g();
};
void ChargeClearAction::vfunc_4() {
    if (!((A_1719f0*)mObj)->flag) {
        B_1719f0* x = ((First_1719f0*)mNext)->f();
        B_1719f0* y = ((Second_1719f0*)x)->g();
        y->value = 0;
    }
}