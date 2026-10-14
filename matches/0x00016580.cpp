struct ObjA_16580 {
    ObjA_16580* f();
};
struct ObjB_16580 {
    ObjB_16580* g();
};
struct ObjC_16580 {
    void h(int);
};
class CInvincibleAction {
    char pad[0x1c];
    ObjA_16580* member;

  public:
    bool vfunc_6(int);
};
bool CInvincibleAction::vfunc_6(int) {
    ObjA_16580* a = member->f();
    ObjB_16580* b = ((ObjB_16580*)a)->g();
    ((ObjC_16580*)b)->h(1);
    return true;
}