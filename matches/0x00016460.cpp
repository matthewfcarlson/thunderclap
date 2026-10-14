class CAction {
    char pad[0x1c];
};
class CSmartPropThrowingAction : public CAction {
  public:
    void vfunc_4();
};
struct HelperA_16460 {
    char pad[0x1c];
    HelperA_16460* f();
    char* g();
};
void CSmartPropThrowingAction::vfunc_4() {
    HelperA_16460* p = *(HelperA_16460**)((char*)this + 0x1c);
    p = p->f();
    char* q = p->g();
    q[0x1f51] = 0;
}