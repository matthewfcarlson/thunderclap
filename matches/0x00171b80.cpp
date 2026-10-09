struct A {
    void* f();
};
struct B {
    void* f();
};
struct C {
    void f(void*, int);
};
class FootPivotAction {
  public:
    char pad[0x20];
    A* member20;
    char pad24[4];
    void* member28;
    void vfunc_4();
};
void FootPivotAction::vfunc_4() {
    void* a = member20->f();
    void* b = ((B*)a)->f();
    if (b)
        ((C*)b)->f(member28, 0);
}