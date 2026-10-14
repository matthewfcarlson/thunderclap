class Obj_2a35d0 {
  public:
    virtual void f0();
    virtual void f1();
};
class DrawableHierarchy {
  public:
    char pad[0x10];
    Obj_2a35d0* member;
    void vfunc_14();
};
void DrawableHierarchy::vfunc_14() {
    if (member) {
        member->f1();
        member = 0;
    }
}