class Aux_16c90 {
  public:
    void helper(int);
};
class CEffectAction {
  public:
    char pad[0x20];
    void* mObj;
    char pad2[4];
    int mArg;
    Aux_16c90* helper1();
    void vfunc_4();
};
void CEffectAction::vfunc_4() {
    Aux_16c90* p = helper1();
    if (*((char*)mObj + 0x50))
        p->helper(mArg);
}