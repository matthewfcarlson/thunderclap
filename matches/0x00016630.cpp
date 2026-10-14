// Same code shape as 0x000165f0 (propagated; names are from that function)
class Inner2_16630 {
  public:
    Inner2_16630* Step2();
    void Step3(int);
};
class Inner1_16630 {
  public:
    Inner2_16630* Step1();
};
class CIntangibleAction {
    char pad[0x1c];
    Inner1_16630* member;

  public:
    void vfunc_4();
};
void CIntangibleAction::vfunc_4() {
    Inner2_16630* p = member->Step1()->Step2();
    p->Step3(0);
}