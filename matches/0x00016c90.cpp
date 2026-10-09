class Aux {
  public:
    void helper(int);
};
class CEffectAction {
  public:
    char pad[0x20];
    void* mObj;
    char pad2[4];
    int mArg;
    Aux* helper1();
    void vfunc_4();
};
void CEffectAction::vfunc_4() {
    Aux* p = helper1();
    if (*((char*)mObj + 0x50))
        p->helper(mArg);
}