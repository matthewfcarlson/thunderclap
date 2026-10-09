class Obj {
  public:
    Obj* A();
    Obj* B();
    void C(int);
};
class NoHitPushbackAction {
  public:
    char pad[0x20];
    Obj* member;
    void vfunc_4();
};
void NoHitPushbackAction::vfunc_4() {
    Obj* p = member;
    if (p) {
        p = p->A();
        p = p->B();
        p->C(0);
    }
}