class MissilePunchAction {
  public:
    char pad[0x20];
    void* member;
    void vfunc_4();
};
struct ObjC;
struct ObjB {
    ObjC* g();
};
struct ObjA {
    ObjB* f();
};
struct ObjC {
    void h(int, int, int);
};
void MissilePunchAction::vfunc_4() {
    if (member) {
        ObjC* c = ((ObjA*)member)->f()->g();
        c->h(0, 0, 0);
    }
}