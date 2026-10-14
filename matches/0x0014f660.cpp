class Obj_14f660 {
  public:
    Obj_14f660* A();
    Obj_14f660* B();
    void C(int);
};
class NoHitPushbackAction {
  public:
    char pad[0x20];
    Obj_14f660* member;
    void vfunc_4();
};
void NoHitPushbackAction::vfunc_4() {
    Obj_14f660* p = member;
    if (p) {
        p = p->A();
        p = p->B();
        p->C(0);
    }
}