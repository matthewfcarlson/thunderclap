struct A_171b80 {
    void* f();
};
struct B_171b80 {
    void* f();
};
struct C_171b80 {
    void f(void*, int);
};
class FootPivotAction {
  public:
    char pad[0x20];
    A_171b80* member20;
    char pad24[4];
    void* member28;
    void vfunc_4();
};
void FootPivotAction::vfunc_4() {
    void* a = member20->f();
    void* b = ((B_171b80*)a)->f();
    if (b)
        ((C_171b80*)b)->f(member28, 0);
}