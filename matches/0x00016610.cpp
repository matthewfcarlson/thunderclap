// Same code shape as 0x00016580 (propagated; names are from that function)
struct ObjA_16610 {
    ObjA_16610* f();
};
struct ObjB_16610 {
    ObjB_16610* g();
};
struct ObjC_16610 {
    void h(int);
};
class CInvincibleAction {
    char pad[0x1c];
    ObjA_16610* member;

  public:
    bool vfunc_6(int);
};
bool CInvincibleAction::vfunc_6(int) {
    ObjA_16610* a = member->f();
    ObjB_16610* b = ((ObjB_16610*)a)->g();
    ((ObjC_16610*)b)->h(1);
    return true;
}