class Inner2_165f0 {
  public:
    Inner2_165f0* Step2();
    void Step3(int);
};
class Inner1_165f0 {
  public:
    Inner2_165f0* Step1();
};
class CIntangibleAction {
    char pad[0x1c];
    Inner1_165f0* member;

  public:
    void vfunc_4();
};
void CIntangibleAction::vfunc_4() {
    Inner2_165f0* p = member->Step1()->Step2();
    p->Step3(0);
}