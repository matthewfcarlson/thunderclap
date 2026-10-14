class MissilePunchAction {
  public:
    char pad[0x20];
    void* member;
    void vfunc_4();
};
struct ObjC_194dd0;
struct ObjB_194dd0 {
    ObjC_194dd0* g();
};
struct ObjA_194dd0 {
    ObjB_194dd0* f();
};
struct ObjC_194dd0 {
    void h(int, int, int);
};
void MissilePunchAction::vfunc_4() {
    if (member) {
        ObjC_194dd0* c = ((ObjA_194dd0*)member)->f()->g();
        c->h(0, 0, 0);
    }
}