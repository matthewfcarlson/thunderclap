// Same code shape as 0x00016580 (propagated; names are from that function)
struct ObjA_17570 {
    ObjA_17570* f();
};
struct ObjB_17570 {
    ObjB_17570* g();
};
struct ObjC_17570 {
    void h(int);
};
class CUninterruptibleAction {
    char pad[0x1c];
    ObjA_17570* member;

  public:
    bool vfunc_6(int);
};
bool CUninterruptibleAction::vfunc_6(int) {
    ObjA_17570* a = member->f();
    ObjB_17570* b = ((ObjB_17570*)a)->g();
    ((ObjC_17570*)b)->h(1);
    return true;
}