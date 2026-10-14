// Same code shape as 0x00016580 (propagated; names are from that function)
struct ObjA_165d0 {
    ObjA_165d0* f();
};
struct ObjB_165d0 {
    ObjB_165d0* g();
};
struct ObjC_165d0 {
    void h(int);
};
class CInvincibleAction {
    char pad[0x1c];
    ObjA_165d0* member;

  public:
    bool vfunc_6(int);
};
bool CInvincibleAction::vfunc_6(int) {
    ObjA_165d0* a = member->f();
    ObjB_165d0* b = ((ObjB_165d0*)a)->g();
    ((ObjC_165d0*)b)->h(1);
    return true;
}