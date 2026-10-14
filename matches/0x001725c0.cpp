struct C_1725c0 {
    void* a;
    void* f592a0();
    void* f59a30();
    void f373e0(int);
};
struct MoveJointAction {
    char pad[0x20];
    C_1725c0* mObj;
    void vfunc_4();
};
void MoveJointAction::vfunc_4() {
    C_1725c0* p = (C_1725c0*)mObj;
    p = (C_1725c0*)p->f592a0();
    p = (C_1725c0*)p->f59a30();
    p->f373e0(1);
}